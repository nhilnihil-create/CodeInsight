#include<bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define sz(a) (int)(a.size())

typedef long long ll;typedef vector<int> vi;
typedef pair<int,int> ii;typedef vector<ii> vii;
typedef vector<vi> vvi;

signed main(){
	IOS
	int n,a,b;cin>>n>>a>>b;
	vi v(n);forn(i,n) cin>>v[i];
	int l=1,r=INT_MAX;int ans=0;
	while(l<=r){
		int m=(l+r)/2;
		int req=0;
		for(int i:v){
			i-=m*b;
			if(i>0)
				req+=(i+(a-b-1))/(a-b);
		}
		if(req<=m){
			ans=m;
			r=m-1;
		}
		else
			l=m+1;
	}
	cout<<ans;
}