#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#define endl '\n';
#define all(v) ((v).begin()), ((v).end())
#define sz(s)               (int)s.size()
#define Ceil(x,y)             ((x+y-1)/y)
#define RT(x)           return cout<<x,0;
#define mem(x,y)    memset(x,y,sizeof(x))
#define vi                    vector<int>
#define pii                 pair<int,int>
#define fx(n)           fixed<<setprecision(n)
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define forr(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef double dl;
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 1e7 + 5, MOD = 1e9 + 7;
using namespace std;
void fast() { std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL); }
int main()
{
	fast();
	ll n;
	cin>>n;
	vector<ll>v(2*n);
	for(int i=0;i<2*n;i++)
        cin>>v[i];
    sort(all(v));
    ll ans=0;
    for(int i=0;i<2*n;i+=2)
    {
        //cout<<v[i]<<" "<<v[i+1]<<"\n";
        ans+=min(v[i],v[i+1]);
    }
    cout<<ans<<"\n";
	return 0;
}
