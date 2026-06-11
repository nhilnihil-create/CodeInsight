#include <bits/stdc++.h>
#include <cmath>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return 1;
	}
	return 0;
}
const long long INFLL = 1LL << 60;
const int INF = 1 << 28;
const long long MOD = 1000000000 + 7;



int main()
{
	string s;
	cin >> s;
	int legth=s.size();
	long long k;
	cin >>k;
	int toA=0;
	for(int i=0;i<legth;i++){
		toA=1+'z'-s[i];
		if(s[i]=='a'){
			toA=0;
		}
		if(k >=toA){
			s[i]='a';
			k-=toA;
		}
	}
	s[legth-1]+=(k%(1+'z'-'a'));
	cout <<s<< endl;
}
