//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
const int mod=998244353;
 
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
 
const int N=200002;

struct Node{
	Node *left,*right;
	int val;
	Node(){
	}
	Node(Node *_left,Node* _right,int _val):left(_left),right(_right),val(_val){
	}
	Node *insert(int tl,int tr,int ind,int vl);
	int query(int tl,int tr,int l,int r){
		if(l>r)return 0;
		if(l<=tl&&tr<=r){
			return val;
		}
		int md=tl+tr>>1;
		return this->left->query(tl,md,l,min(r,md))+this->right->query(md+1,tr,max(md+1,l),r);		
	}
};
 
Node abcd[N*50];
int sz=50*N;
Node *newNode(Node *left,Node *right,int val){
	abcd[--sz]=Node(left,right,val);
	return &abcd[sz];
}
	
Node *null=newNode(NULL,NULL,0);
 
Node *Node::insert(int tl,int tr,int ind,int vl){
	if(tl==tr&&ind==tl){
		return newNode(null,null,val+vl);
	}
	int md=tl+tr>>1;
	if(ind<=md&&ind>=tl){
		return newNode(this->left->insert(tl,md,ind,vl),this->right,val+vl);
	}
	else if(ind>md&&ind<=tr){
		return newNode(this->left,this->right->insert(md+1,tr,ind,vl),val+vl);
		
	}
	return this;
	
}
 
Node *rt[N];
 
void solve(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>>a(n);
  cin>>a;
  sort(all(a));
  null->left=null->right=null;
  rt[0]=null;
  for(int i=0;i<n;i++){
	  rt[i+1]=rt[i]->insert(1,m,a[i].S,1);
  }
  for(int i=1;i<=m;i++){
	  int ans=0;
	  for(int j=i;j<=m;j+=i){
		  int lf=lower_bound(all(a),mp(j-i+1,-1))-a.begin();
		  int rg=lower_bound(all(a),mp(j,(int)1e9))-a.begin();
		  rg--;
		  ans+=rt[rg+1]->query(1,m,j,m);
		  ans-=rt[lf]->query(1,m,j,m);
	  }
	  cout<<ans<<'\n';
  }
}  
 
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc=1;
  //cin>>tc;
  for(int _=0;_<tc;_++){
	// cout<<"Case #"<<_+1<<": ";
	solve();
	if(_!=tc-1){
	  cout<<'\n';
	}
  }
}
