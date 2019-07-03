#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class boyermoore
{
public:
	vector<int> ans;
	int *gs,*osuf,*prefix;
	map<char,int> bc;
	int n;

	boyermoore();
	void init(string &p);
	void getgs(string &p);
	void getbc(string &p);
	void cal(string &t,string &p);
};

template <typename K, typename V>
V GetWithDef(const  std::map <K,V> & m, const K & key, const V & defval ) 
{
   typename std::map<K,V>::const_iterator it = m.find( key );
   if ( it == m.end() ) {
      return defval;
   }
   else {
      return it->second;
   }
}