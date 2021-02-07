#pragma once

#include "CMatrix.h"
#include <afxwin.h>

void PrintMatrix(CDC*, int, int, CMatrix&);

void FillMatrix(CMatrix&, int);

CMatrix VectorMult(CMatrix&, CMatrix&);

double ScalarMult(CMatrix&, CMatrix&);

double ModVec(CMatrix&);

double cosV1V2(CMatrix&, CMatrix&);

void PrintNum(CDC*, int, int, double);

CMatrix SphereToCart(CMatrix&);

void DoublePrintMatrix(CDC*, int, int, CMatrix&);