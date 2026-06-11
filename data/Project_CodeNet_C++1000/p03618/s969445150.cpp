//do u need something?
#include <bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/t_policy.hpp>
using namespace __gnu_pbds;
//*/
/*
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
//*/

std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
using namespace std;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define y1 asjfkgasj
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define flsh '\n'<<flush
#define pii pair<int,int>
#define pll pair<long long,long long>
#define deb(x) cout<< #x <<'='<< x <<flsh;
#define ull unsigned long long
#define intt long long
#define ll long long
#define ld long double
#define dd double
#define OK cout<<"OK\n"<<flsh;
#define setpre(x) fixed<<setprecision(x)
#define mmset(x,y) memset(x,y,sizeof(x))
const ll mod=998244353;

ll n,ans,a[26];
string s;
int main()
{
	IO;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
		a[s[i]-'a']++;
	ans=(n*(n-1))/2;
	for(int i=0;i<26;i++)
		ans-=(a[i]*(a[i]-1))/2;
	cout<<ans+1<<endl;
	return 0;
}