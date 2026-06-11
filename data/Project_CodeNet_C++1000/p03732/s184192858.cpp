#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 2000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 0
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int ceil2(int a,int b){if(a%b){return a/b+1;}else{return a/b;}}
using namespace std;

int n,W,ans;
int w[111],v[111];
signed main(){
	cin>>n>>W;
	rep(i,n)cin>>w[i]>>v[i];
	vector<int> s[4];
	rep(i,n){
		s[w[i]-w[0]].push_back(v[i]);
	}
	rep(i,4){
		sort(s[i].begin(),s[i].end(),greater<>());	
	}
	int sum0=0;
	rep(i,s[0].size()+1){
		int sum1=0;
		if(i!=0)sum0+=s[0][i-1];
		rep(j,s[1].size()+1){
			int sum2=0;
			if(j!=0)sum1+=s[1][j-1];
			rep(k,s[2].size()+1){
				if(k!=0)sum2+=s[2][k-1];
				int sum=sum0+sum1+sum2,sum3=0,cnt=0;
				rep(l,s[3].size()){
					if(i*w[0]+j*(w[0]+1)+k*(w[0]+2)+(l+1)*(w[0]+3)>W){
						cnt=l;
						break;
					}
					sum3+=s[3][l];
				}
				sum+=sum3;
				if(i*w[0]+j*(w[0]+1)+k*(w[0]+2)+cnt*(w[0]+3)<=W)ans=max(ans,sum);
			//	cout<<i<<" "<<j<<" "<<k<<" "<<cnt<<" "<<"sum:"<<sum<<endl;
			}
		}
	}
	cout<<ans<<endl;
}