#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int mod = 1e9+7;
const int mx = INT_MAX;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define file "orz"
const int mxN=1e5+5;
int n, arr[mxN], cnt[mxN], occ[mxN];
signed main()
{
    //freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    priority_queue<pii> pq;
    for(int i=1;i<=n;i++)
    {
    	cnt[i]=1;
    	cin>>arr[i];
    	pq.push(mp(arr[i],i));
	}
	while(pq.size()>=2)
	{
		auto temp=pq.top();
		pq.pop();
		auto temp2=pq.top();
		pq.pop();
		occ[temp.se] += cnt[temp.se]*(temp.fi-temp2.fi);
		cnt[min(temp.se,temp2.se)]+=cnt[max(temp.se,temp2.se)];
		pq.push(mp(temp2.fi,min(temp.se,temp2.se)));
	}
	cout<<occ[1]+n*pq.top().fi<<"\n";
	for(int i=2;i<=n;i++)
		cout<<occ[i]<<"\n";
}
