/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll        long long
#define ull       unsigned long long
#define si(x)     scanf("%d", &x)
#define sll(x)    scanf("%lld", &x)
#define ssll(x,y)    scanf("%lld %lld", &x ,&y)
#define sd(x)     scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100005
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
		ll x=0;
		int n;
		string s;
		cin >> n >> s;
		vector<int>v;
		for (int i=0 ; i<n ; i++)
		{
			if(s[i]=='I') x++;
			v.pb(x);
			//ll store=x;
			//x=max((ll)0,x);
			//cerr << imie(x);
			if (s[i]=='D') x--;
			v.pb(x);
			//x=max(store,x);
		}
		//for (auto x:v)
		//cout << x << endl;
		sort(v.rbegin(),v.rend());
		cout << v[0] << endl;
		return 0;  
}  
