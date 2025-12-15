#include "task1.h"
#include <cmath>

// небольшая вспомогательная функция
namespace {
int sign(double x, double eps = 1e-9)
{
    if (x > eps)  return 1;
    if (x < -eps) return -1;
    return 0;
}
}

int pointRelativeToSegment(const Point& A, const Point& B, const Point& P)
{
    // Векторы AB и AP
    double ABx = B.x - A.x;
    double ABy = B.y - A.y;
    double APx = P.x - A.x;
    double APy = P.y - A.y;

    // Векторное произведение в 2D: AB x AP
    double cross = ABx * APy - ABy * APx;
    int s = sign(cross);

    if (s == 1)  return 1;   // P слева от направленного отрезка A->B
    if (s == -1) return -1;  // P справа

    // s == 0: точка коллинеарна прямой AB.
    // Проверим, лежит ли она на отрезке (между A и B).
    double dot  = ABx * APx + ABy * APy;          // скалярное AB·AP
    double len2 = ABx * ABx + ABy * ABy;          // |AB|^2

    if (dot < -1e-9 || dot > len2 + 1e-9) {
        // коллинеарна, но вне отрезка — все равно возвращаем 0 по условию
        return 0;
    }

    return 0;  // коллинеарна и на отрезке
}
