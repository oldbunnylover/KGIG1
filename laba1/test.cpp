#include "CMatrix.h"
#include "test.h"
#include "pch.h"

void PrintMatrix(CDC* dc, int x, int y, CMatrix& matrix)
{
	CString str = L"";
	for (int i = 0; i < matrix.rows(); i++)
	{
		for (int j = 0; j < matrix.cols(); j++)
		{
			str.Format(L"%.0lf", matrix(i, j));
			dc->TextOut(x + j * 50, y + i * 50, str);
		}
	}
}

void DoublePrintMatrix(CDC* dc, int x, int y, CMatrix& matrix)
{
	CString str = L"";
	for (int i = 0; i < matrix.rows(); i++)
	{
		for (int j = 0; j < matrix.cols(); j++)
		{
			str.Format(L"%.2lf", matrix(i, j));
			dc->TextOut(x + j * 50, y + i * 50, str);
		}
	}
}


void FillMatrix(CMatrix& matrix, int start) {
	for (int i = 0; i < matrix.rows(); i++)
	{
		for (int j = 0; j < matrix.cols(); j++)
		{
			matrix(i, j) = start;
			start++;
		}
	}
}

CMatrix VectorMult(CMatrix& V1, CMatrix& V2) 
{
	CMatrix result(3);
	result(0) = V1(1) * V2(2) - V1(2) * V2(1);
	result(1) = V1(2) * V2(0) - V1(0) * V2(2);
	result(2) = V1(0) * V2(1) - V1(1) * V2(0);
	return result;
}

double ScalarMult(CMatrix& V1, CMatrix& V2)
{
	double result = 0;
	for (int i = 0; i < V1.rows(); i++)
	{
		result += V1(i) * V2(i);
	}
	return result;
}

double ModVec(CMatrix& V) 
{
	double result = 0;
	for (int i = 0; i < V.rows(); i++)
	{
		result += pow(V(i), 2);
	}
	return sqrt(result);
}

double cosV1V2(CMatrix& V1, CMatrix& V2)
{
	double result = 0;
	result = ScalarMult(V1, V2) / ModVec(V1) / ModVec(V2);
	return result;
}

void PrintNum(CDC* dc, int x, int y, double num) {
	CString str = L"";
	str.Format(L"%.2lf", num);
	dc->TextOut(x, y, str);
}

CMatrix SphereToCart(CMatrix& PView)
{
	double r = PView(0);
	double theta = PView(1);
	double phi = PView(2);

	CMatrix result(3);
	result(0) = r * sin(theta) * cos(phi);
	result(1) = r * sin(theta) * sin(phi);
	result(2) = r * cos(theta);
	return result;
}