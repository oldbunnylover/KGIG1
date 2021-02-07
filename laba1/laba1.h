
// laba1.h: основной файл заголовка для приложения laba1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Claba1App:
// Сведения о реализации этого класса: laba1.cpp
//

class Claba1App : public CWinApp
{
public:
	Claba1App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Claba1App theApp;
