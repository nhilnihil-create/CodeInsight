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
	string s;
	cin>>s;

	bool ok=1;
	rep(i,s.size()-1)if(s[i]!=s[i+1])ok=false;

	if(ok){
		cout<<0<<endl;
		return 0;
	}
	int ans=INF;
	rep(tar,26){
		// char tar='a'+ii;
		vi str(s.size(),-1);
		rep(i,s.size())str[i]=s[i]-'a';

	


		for(int len=s.size();len>0;len--){
			rep(i,len-1){
				if(str[i]==tar||str[i+1]==tar){
					str[i]=tar;
				}
			}
			bool ok=1;
			rep(i,len-2) if(str[i]!=str[i+1])ok=false;
			if(ok){
				chmin(ans,(int)s.size()-(len-1));
				break;
			}
			
		}

	}
	cout<<ans<<endl;

	
	return 0;
}