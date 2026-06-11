#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	int h,w;
	cin>>h>>w;
	vector<vector<char>>vec;
	for(int i=0;i<h;i++){
		string s;
		cin>>s;
		vector<char>v;
		for(int j=0;j<w;j++){
			v.push_back(s[j]);
		}
		vec.push_back(v);
		vec.push_back(v);
	}
	for(int i=0;i<2*h;i++){
		for(int j=0;j<w;j++){
			cout << vec[i][j];
		}
		cout << endl;
	}
}