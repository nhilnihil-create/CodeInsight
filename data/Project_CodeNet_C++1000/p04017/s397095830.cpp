//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;
#define int ll
#define all(a) begin(a),end(a)
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int mod=1e9+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int mul(int a,int b){
  return ((a)*1ll*(b))%mod;
}

void add(int &a,int b){
  a+=b;
  if(a>=mod)a-=mod;
}

int sub(int a,int b){
  a-=b;
  if(a<0){
    a+=mod;
  }
  return a;
}

int powz(int a,int b){
  int res=1;
  while(b){
    if(b&1){
      res=mul(res,a);
    }
    b/=2;
    a=mul(a,a);
  }
  return res;
}

template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
  input>>x.F>>x.S;
  return input;
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}

template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
    output<<i<<' ';
  return output;
}

template<typename T>
vector<pair<T,int>> getvec(int n){
  vector<pair<T,int>>a(n);
  for(int i=0;i<a.size();i++){
    cin>>a[i].F;
    a[i].S=i;
  }
  return a;
}

void clr(auto &a,int n){
  a.clear();
  a.resize(n);
}

void unq(auto &a){
  sort(all(a));
  a.resize(unique(all(a))-a.begin());
}

const int N=100005;

int cycleNo[N];
vector<int>adj[N];
bool vis[N];
int nxt[N];
int n;

void dfs(int u,int p){
	if(u==n-1){
		return;
	}
	vis[u]=true;
	cycleNo[u]=p;
	adj[p].pb(u);
	dfs(nxt[u],p);	
}

int sparse_table[N][22];

void solve(){
	cin>>n;
	vi a(n);
	cin>>a;
	int L;
	cin>>L;
	int q;
	cin>>q;
	vector<pair<int,int>>queries;
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		queries.pb({x,y});
	}
	vector<int>ans(q);
	vector<int>prf(n);
	for(int i=0;i<n-1;i++){
		prf[i+1]=a[i+1]-a[i];
		prf[i+1]+=prf[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<22;j++){
			sparse_table[i][j]=1e9;
		}
	}
	for(int i=n-2;i>=0;i--){
		int l=i+1,r=n-1;
		int con=prf[i],val=i+1;
		while(l<=r){
			int mid=(l+r)/2;
			if((prf[mid]-con)<=L){
				l=mid+1;
				val=max(val,mid);
			}
			else{
				r=mid-1;
			}
		}
		nxt[i]=val;
		sparse_table[i][0]=val;
	}
	sparse_table[n-1][0]=n-1;
	for(int i=1;i<22;i++){
		for(int j=0;j<n;j++){
			if(sparse_table[j][i-1]==n-1){
				sparse_table[j][i]=n-1;
			}
			else
			sparse_table[j][i]=sparse_table[sparse_table[j][i-1]][i-1];
		}
	}	
	for(int i=0;i<q;i++){
		int x,y;
		tie(x,y)=queries[i];
		if(x<y){
			for(int j=21;j>=0;j--){
				int cr=x;
				for(int k=0;k<j;k++){
					cr=sparse_table[cr][k];
				}
				if(cr<y){
					ans[i]|=1<<j;
					x=sparse_table[x][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		nxt[i]=0;
		prf[i]=0;
	}
	reverse(all(a));
	for(int i=0;i<n-1;i++){
		for(int j=0;j<22;j++){
			sparse_table[i][j]=1e9;
		}
	}
	sparse_table[n-1][0]=n-1;
	for(int i=0;i<n-1;i++){
		prf[i+1]=abs(a[i+1]-a[i]);
		prf[i+1]+=prf[i];
	}
	for(int i=n-2;i>=0;i--){
		int l=i+1,r=n-1;
		int con=prf[i],val=i+1;
		while(l<=r){
			int mid=(l+r)/2;
			if((prf[mid]-con)<=L){
				l=mid+1;
				val=max(val,mid);
			}
			else{
				r=mid-1;
			}
		}
		nxt[i]=val;
		sparse_table[i][0]=val;
	}
	for(int i=1;i<22;i++){
		for(int j=0;j<n;j++){
			if(sparse_table[j][i-1]==n-1){
				sparse_table[j][i]=n-1;
			}
			else{
				sparse_table[j][i]=sparse_table[sparse_table[j][i-1]][i-1];
			}
		}
	}	
	for(int i=0;i<q;i++){
		int x,y;
		tie(x,y)=queries[i];
		x=n-x-1;
		y=n-y-1;
		if(x<y){
			debug("AA");
			for(int j=21;j>=0;j--){
				int cr=x;
				for(int k=0;k<j;k++){
					if(j==3){
						debug(cr);
					}
					cr=sparse_table[cr][k];
					if(j==3){
						debug(cr);
					}
				}
				//~debug(cr,j,x,y);
				if(cr<y){
					debug(j,cr,j,x,y);
					ans[i]|=1<<j;
					x=sparse_table[x][j];
				}
				if(x==y){
					break;
				}
			}
		}
	}
	for(auto i:ans){
		cout<<i<<'\n';
	}
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc=1;
  //cin>>tc;
  for(int _=0;_<tc;_++){
    //~cout<<"Case #"<<_+1<<": ";
    solve();
    if(_!=tc-1){
      cout<<'\n';
    }
  }
}

