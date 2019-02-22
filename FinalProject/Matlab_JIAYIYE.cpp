using namespace std;
#include "StockAccount.h"
#include "string.h"
#pragma comment(lib, "libmx.lib" )  
#pragma comment( lib, "libmex.lib" ) 
#pragma comment( lib, "libeng.lib")
#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h" 
#include <engine.h>

void StockAccount::viewGraphPortfolioValue()
{
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL)
	{
		cout << "Error: Not Found"
			<< endl;
		exit(1);
	}



	double x[1];
	mxArray *m_X;
	m_X = mxCreateDoubleMatrix(1, 1, mxREAL);
	memcpy((void *)mxGetPr(m_X), (void *)x, sizeof(double) * 1);
	engPutVariable(ep, "x", m_X);

	

	engEvalString(ep, "x = 1:1 : 10); " );
	engEvalString(ep, "y = x. ^ 2; ");
	engEvalString(ep, "plot(x, y); ");



}
