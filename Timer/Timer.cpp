// Timer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Timer.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
			double delay = 1;
			WORD sleepTime = delay * 0.8 * 1000;
			SYSTEMTIME st;
			GetSystemTime(&st);
			WORD startMS = st.wMilliseconds;
			WORD startS = st.wSecond;
			while (true){				
				GetSystemTime(&st);
				if (st.wMilliseconds == startMS && st.wSecond == (startS+(WORD)delay)%60){
					printf("%d:%d\n", st.wSecond, st.wMilliseconds);
					startS = st.wSecond;
					Sleep(sleepTime);
				}
			}
			
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
