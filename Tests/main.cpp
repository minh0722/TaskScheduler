#ifdef _WIN32

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <windows.h>

#pragma comment( lib, "winmm.lib" )

#endif

#include <stdio.h>
#include <string>
#include <set>

#include <MTScheduler.h>
#include "Tests/Tests.h"


//#include <MTMicroWebSrv.h>

int main(int UNUSED(argc), char ** UNUSED(argv))
{
/*
	MT::MicroWebServer webSrv;
	webSrv.Serve(8080, 8080);

	char xxx[8192];
	GetCurrentDirectoryA(MT_ARRAY_SIZE(xxx), xxx);
	printf("%s\n", xxx);

	for(;;)
	{
		webSrv.Update();
	}
*/

#ifdef _WIN32
	timeBeginPeriod(1);
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG );
#endif

	//while(true)
	{
		Tests::RunAll();
	}


#ifdef _WIN32
	 _CrtDumpMemoryLeaks();
	 timeEndPeriod(1);
#endif

	return 0;
}



