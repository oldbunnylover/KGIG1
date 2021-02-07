
// ChildView.cpp: реализация класса CChildView
//

#include "pch.h"
#include "framework.h"
#include "laba1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "test.h"


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_APP_MATRIX, &CChildView::MatrixTest)
	ON_COMMAND(ID_APP_FUNC, &CChildView::FuncTest)
END_MESSAGE_MAP()



// Обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	
	// TODO: Добавьте код обработки сообщений
	
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}

void CChildView::MatrixTest() 
{
	CDC* dc = GetDC();
	RedrawWindow();

	CMatrix A(3, 3);
	FillMatrix(A, 1);
	PrintMatrix(dc, 50, 50, A);

	CMatrix B(3, 3);
	FillMatrix(B, 10);
	PrintMatrix(dc, 250, 50, B);

	CMatrix V1(3);
	FillMatrix(V1, 1);
	CMatrix V2(3);
	FillMatrix(V2, 4);

	PrintMatrix(dc, 450, 50, V1);
	PrintMatrix(dc, 550, 50, V2);

	CMatrix C1 = A + B;
	CMatrix C2 = A * B;

	CMatrix D = A * V1;
	CMatrix q = V1.Transp() * V2;
	CMatrix p = V1.Transp() * A * V2;

	PrintMatrix(dc, 50, 250, C1);
	PrintMatrix(dc, 250, 250, C2);
	PrintMatrix(dc, 450, 250, D);
	PrintMatrix(dc, 550, 300, q);
	PrintMatrix(dc, 650, 300, p);
}

void CChildView::FuncTest() {
	CDC* dc = GetDC();
	RedrawWindow();

	CMatrix V1(3);
	FillMatrix(V1, 1);
	CMatrix V2(3);
	FillMatrix(V2, 4);

	CMatrix vMult = VectorMult(V1, V2);
	PrintMatrix(dc, 50, 50, vMult);

	CMatrix sMult(1);
	FillMatrix(sMult, ScalarMult(V1, V2));
	PrintMatrix(dc, 150, 100, sMult);

	double mod = ModVec(V2);
	PrintNum(dc, 250, 100, mod);

	double cos = cosV1V2(V1, V2);
	PrintNum(dc, 350, 100, cos);

	CMatrix STC = SphereToCart(V1);
	DoublePrintMatrix(dc, 450, 50, STC);
}