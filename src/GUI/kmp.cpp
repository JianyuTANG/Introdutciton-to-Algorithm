#include "kmp.h"

knuthmorrispratt::knuthmorrispratt():prefix(nullptr),n(0)
{
}

void knuthmorrispratt::init(string &p)
{
	n=p.size();
	if(prefix!=nullptr)
		delete prefix;
	prefix=nullptr;
	prefix=new int[n];
	ans.clear();
	getprefix(p);
}

void knuthmorrispratt::getprefix(string &p)
{
	prefix[1]=0;
	int k=0;
	for(int i=2;i<n;i++)
	{
		while(k>0&&p[k+1]!=p[i])
			k=prefix[k];
		if(p[k+1]==p[i])
			k=k+1;
		prefix[i]=k;
	}
}

void knuthmorrispratt::cal(string &t,string &p)
{
	int m=t.size();
	int q=0;
	for(int i=0;i<m;i++)
	{
		while(q>0&&p[q+1]!=t[i])
			q=prefix[q];
		if(p[q+1]==t[i])
			q++;
		if(q==n-1)
		{
			ans.push_back(i-n+2);
			q=prefix[q];
		}
	}
}