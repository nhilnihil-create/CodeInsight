//============================================================================
// Name        : hoba.cpp :)
// Author      : (O_O Diab) (Why_not) (el 3AQ)
// Version     :
// Copyright   : please, Don't touch me :(
// Description : problem in C++
//============================================================================
#include <bits/stdc++.h>
#define ll long long
#define rw freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define pb push_back
#define F first
#define S second
#define pf push_front
#define lp(i,a,b) for (int i=a;i<=(int)b;++i)
#define lp2(i,a,b) for (int i=a;i>=b;--i)
#define f(x) return cout<<x<<"\n",0
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define p(x) cout<<#x<<" = { "<<x<<" } \n"
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define EPS 1e-6
// to convert string to number use int a = stoi(string);
// to convert number to string use string s = to_string(int);
#define FAST ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define clr(c,x) memset(c,x,sizeof(c));
using namespace std;
const int N = 1e2 + 5, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };

int main() {
#ifdef ONLINE_JUDGE
    FAST;
#endif
	string s;
	cin >> s;
	if (s[0]==s[s.size()-1])
	{
		if (s.size()&1) f("Second");
		f("First");
	}
	if (s.size()&1) f("First");
	f("Second");
	return 0;
}