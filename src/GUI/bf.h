#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class brutalforce
{
public:
	vector<int> ans;
	int n;

	brutalforce();
	void init(string &p);
	void cal(string &t,string &p);
};