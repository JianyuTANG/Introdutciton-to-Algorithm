#include "bm.h"

boyermoore::boyermoore():gs(nullptr),n(0),osuf(nullptr),prefix(nullptr)
{
}

void boyermoore::init(string &p)
{
	n=p.size();
	if(gs!=nullptr)
	{
		delete gs;
		gs=nullptr;
	}
	gs=new int[n];
	if(osuf!=nullptr)
	{
		delete osuf;
		osuf=nullptr;
	}
	osuf=new int[n];
	if(prefix!=nullptr)
		delete prefix;
	prefix=nullptr;
	prefix=new int[n];
	ans.clear();
	bc.clear();
	getbc(p);
	getgs(p);
}

void boyermoore::getbc(string &p)
{
	for(int i=1;i<n;i++)
		bc[p[i]]=n-1-i;
}

void boyermoore::getgs(string &p)
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
	osuf[n-1]=n-1;
	osuf[1]=(int)(p[1]==p[n-1]);
	osuf[0]=0;
	for(int i=2;i<n-1;i++)
	{
		osuf[i]=osuf[prefix[i]];
		if(osuf[i]==prefix[i])
		{
			int t=i-osuf[i];
			while(t>=1&&p[t]==p[n-1-i+t])
			{
				t--;
			}
			osuf[i]=i-t;
		}
	}
	/*
	for(int i=1;i<n;i++)
		cout<<osuf[i]<<" ";
	cout<<"\n";
	*/

	//above is calculating overlapping suffix

	for(int i=1;i<n;i++)
		gs[i]=n-1;
	int j=1;
	for(int i=n-2;i>=1;i--)
	{
		if(osuf[i]==i)
			while(j<=n-1-i)
			{
				if(gs[j]==n-1)
					gs[j]=n-1-i;
				j++;
			}
	}
	for(int i=1;i<n;i++)
		gs[n-1-osuf[i]]=n-1-i;
	/*
	for(int i=1;i<n;i++)
		cout<<gs[i]<<" ";
	cout<<"\n";
	*/
}

void boyermoore::cal(string &t,string &p)
{
	int m=t.size();
	int s=-1;
	int i;
	while(s<m-n+1)
	{
		i=n-1;
		while(p[i]==t[s+i])
		{
			if(i==1)
			{
				ans.push_back(s+1);
				break;
			}
			else
				i--;
		}
		int k=GetWithDef<char,int>(bc,t[s+i],n-1)-n+1+i;
		//cout<<s<<" "<<((k>=gs[i])?k:gs[i])<<"\n";
		s+=(k>=gs[i])?k:gs[i];
		
	}
}