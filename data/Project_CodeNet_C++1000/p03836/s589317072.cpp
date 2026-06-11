#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/
signed main(){
	int sx,sy,tx,ty;
	cin>>sx>>sy>>tx>>ty;

	rep(i,ty-sy)cout<<'U';
	rep(i,tx-sx)cout<<'R';
	rep(i,ty-sy)cout<<'D';
	rep(i,tx-sx)cout<<'L';
	
	cout<<'L';
	rep(i,ty-sy+1)cout<<'U';
	rep(i,tx-sx+1)cout<<'R';
	cout<<'D';
	cout<<'R';
	rep(i,ty-sy+1)cout<<'D';
	rep(i,tx-sx+1)cout<<'L';
	cout<<'U';
	cout<<endl;


	return 0;
}