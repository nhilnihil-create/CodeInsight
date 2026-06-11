/*
 * author :Sadik Hassan
 *  
 * created : 21.01.2020 17:28:06
 * 
 * 
 * 
*/
#include "bits/stdc++.h"
using namespace std;
#define ll            long long
#define nl            "\n"
#define PB            push_back
#define fi            first
#define se            second
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#define rep(i,n)      for(int i=0;i<n;i++)
#define repn(i,n)     for(int i=1;i<=n;i++)
#define rrep(i,n)     for(int i=n-1;i>=0;i--)
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
const int N = 1e9+10;

int main()
{
    _SAD()
    string s,ss="CODEFESTIVAL2016";
	int cnt=0;
	cin>>s;
	for(int i=0;i<SZ(s);i++)
	{
		if(s[i]!=ss[i])
		{
			cnt++;
		}
	}
	cout<<cnt<<nl;
    return 0;
}
