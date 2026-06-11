#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int(i)=int (a);i<=int (b);i++)
#define ff(i,a,b) for(int(i)=int (a);i<int (b);i++)
#define F(i,a,b) for(int(i)=int (a);i>=int (b);i--)
#define foreach(i,x) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define vt vector
#define ll long long
#define lower(p,x) lower_bound(all(p),x)
#define upper(p,x) upper_bound(all(p),x)
#define ms(a,x) memset(a,x,sizeof a)
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const double pi=acos(-1.0);//NOTE:PI
const double eps=1e-5;
const int INF=1e9,mod=1e9+7,N=1e6+1;
string s;
int main(){
	cin>>s;
	int ans=0;
	ff(i,0,s.size()-1){
		if(s[i]!=s[i+1]) ans++;
	}
	cout<<ans;
}