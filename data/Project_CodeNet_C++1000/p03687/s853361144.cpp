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

int n,ans=78678666,k;
int cnt[26];
vector<char> v;
signed main(){
	string s,r;
	cin>>s;
	r=s;
	n=s.size();
	rep(i,n){
		cnt[s[i]-'a']++;
	}
	int max=0;
	rep(i,26){
		if(max<cnt[i]){
			max=cnt[i];
		}
	}
	if(max==n){cout<<0<<endl;return 0;}
	rep(i,n){
		v.push_back(s[i]);
	}
	
	for(auto x:v){
		int flag=1,sans=0;
		s=r;n=s.size();
		n--;
		while(flag){
			string t;
			rep(i,n){
				if(s[i]==x)t+=s[i];
				else if(s[i+1]==x)t+=s[i+1];
				else t+=s[i];
			}
			s=t;
			int flag2=1;
			rep(i,s.size()-1){
				if(s[i]!=s[i+1])flag2=0;
			}
			if(flag2)flag=0;
			n--;sans++;
			//cout<<s<<endl;
		}
		ans=min(ans,sans);
	}
	cout<<ans<<endl;
}
