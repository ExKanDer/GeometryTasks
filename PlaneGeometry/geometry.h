#pragma once
#include "point.h"

/// Возвращает:
///  1  - точка слева от направленного отрезка AB
/// -1  - справа
///  0  - лежит на отрезке (коллинеарна и между A и B)
int pointRelativeToSegment(const Point& A, const Point& B, const Point& P);
