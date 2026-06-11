#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;

int gcd(int a, int b)
{
  if (b==0)
    return a;
  return gcd(b,a%b);
}

int main()
{
	fastio;
	int n, k;
	cin>>n>>k;
	vector<int> a(n);
	range(i,0,n)
		cin>>a[i];
	sort(a.begin(),a.end());
	if(a.back()<k)
	{
		cout<<"IMPOSSIBLE\n";
	}
	else
	{
		int hcf=a[0];
		for(int i=0;i<n;i++)
			hcf=gcd(hcf,a[i]);
		//cout<<hcf<<endl;
		cout<<(k%hcf?"IMPOSSIBLE":"POSSIBLE")<<endl;
	}
}
