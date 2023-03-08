

#include "Function.h"

void swap(float& a, float& b) {
    float n = a;
    a = b;
    b = n;
}

void collizionWall(Layer A[], int size) {

    for (int i = 0; i < size; i++) {

        A[i].SetX(A[i].GetX() + A[i].GetDx());
        A[i].SetY(A[i].GetY() + A[i].GetDy());

        if ((A[i].GetX() + A[i].GetR() > WEIGHT) || (A[i].GetX() - A[i].GetR() < 0)) {
            A[i].SetDx(-A[i].GetDx());
        }
        if ((A[i].GetY() + A[i].GetR() > HEIGHT) || (A[i].GetY() - A[i].GetR() < 0)) {
            A[i].SetDy(-A[i].GetDy());
        }

        if (A[i].GetY() < A[i].GetR()) A[i].SetY(A[i].GetR());
        if (A[i].GetY() > HEIGHT - A[i].GetR()) A[i].SetY(HEIGHT - A[i].GetR());
        if (A[i].GetX() < A[i].GetR()) A[i].SetX(A[i].GetR());
        if (A[i].GetX() > WEIGHT - A[i].GetR()) A[i].SetX(WEIGHT - A[i].GetR());

    }
}

void collizionLayer(Layer A[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {

            float dx = A[i].GetX() - A[j].GetX();
            float dy = A[i].GetY() - A[j].GetY();

            float d = sqrt(dx * dx + dy * dy);

            float sin = dx / d;
            float cos = dy / d;

            float dt = (A[i].GetR() + A[j].GetR() - d);

            if (d < A[i].GetR() + A[j].GetR()) {

                if (dt > (A[i].GetR() + A[j].GetR()) / 20) {
                    detectedLayer(A[i], A[j], dt, sin, cos);
                }

                float Vx1 = A[j].GetDx() * sin + A[j].GetDy() * cos;
                float Vy1 = A[j].GetDy() * sin - A[j].GetDx() * cos;
                float Vx2 = A[i].GetDx() * sin + A[i].GetDy() * cos;
                float Vy2 = A[i].GetDy() * sin - A[i].GetDx() * cos;

                swap(Vx1, Vx2);

                A[i].SetDx(Vx2 * sin - Vy2 * cos);
                A[i].SetDy(Vx2 * cos + Vy2 * sin);
                A[j].SetDx(Vx1 * sin - Vy1 * cos);
                A[j].SetDy(Vx1 * cos + Vy1 * sin);

            }
        }
    }
}

void detectedLayer(Layer& A, Layer& B, float dt, float sin, float cos) {

    float tx = dt * sin;
    float ty = dt * cos;

    A.SetX(A.GetX() + tx / 2);
    B.SetX(B.GetX() - tx / 2);

    A.SetY(A.GetY() + ty / 2);
    B.SetY(B.GetY() - ty / 2);

}

void drawLayer(Layer A[], CircleShape shape, RenderWindow& window, int size) {

    for (int i = 0; i < size; i++) {
        shape.setRadius(A[i].GetR());
        shape.setOrigin(A[i].GetR(), A[i].GetR());
        shape.setPosition(A[i].GetX(), A[i].GetY());
        shape.setFillColor(A[i].GetCol());
        window.draw(shape);
    }
}