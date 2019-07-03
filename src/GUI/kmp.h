#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class knuthmorrispratt
{
public:
	int *prefix;
	vector<int> ans;
	int n;

	knuthmorrispratt();
	void init(string &p);
	void getprefix(string &p);
	void cal(string &t,string &p);
};