#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	cout << char(a.at(0) + ('A' - 'a')) << char(b.at(0) + ('A' - 'a'))<< char(c.at(0) + ('A' - 'a'))<<endl;
} 