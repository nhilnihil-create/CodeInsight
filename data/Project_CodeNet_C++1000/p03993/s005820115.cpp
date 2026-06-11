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
#define PI 3.14159265358979323846
#define INF 2000000007
#define LINF 2000000000000000007
#define MOD 1000000007
#define MOD2 998244353
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
int ans;
int n,a[111111];
signed main(){
	cin>>n;
	rep(i,n){
		cin>>a[i];
		a[i]--;
	}
	int f[111111]={0};
	rep(i,n){
		if(f[i])continue;
		if(a[i]==a[a[a[i]]]&&a[a[i]]==i){
			ans++;
			f[i]=1;
			f[a[i]]=1;
		}
	}
	cout<<ans<<endl;
	
}
