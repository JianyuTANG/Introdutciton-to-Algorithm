#include "bf.h"

brutalforce::brutalforce():n(0)
{
}

void brutalforce::init(string &p)
{
	n=p.size();
	ans.clear();
}

void brutalforce::cal(string &t,string &p)
{
	int q=0;
	int m=t.size();
	for(int i=0;i<m;i++)
	{
		if(t[i]==p[q+1])
			q++;
		else
		{
			i-=q;
			q=0;
		}
		if(q==n-1)
		{
			ans.push_back(i-n+2);
			i-=q-1;
			q=0;
		}
	}
}