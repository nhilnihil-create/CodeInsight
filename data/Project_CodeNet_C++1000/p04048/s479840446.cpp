#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 233;
ll cal(ll a,ll b){
	if(a<b)swap(a,b);
	if(a==b)return a;
	ll k = (a-1)/b;
	return cal(a-k*b,b)+2*k*b;
}
int main()
{
	ll n,x;cin>>n>>x;
	cout << cal(n-x,x)+n << endl;
	return 0;
}
