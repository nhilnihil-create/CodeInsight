#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
using namespace std;
using ll=long long;
#define double long double
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
// using llset=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define For(i,a,b) for(i=a;i<(ll)b;++i)
#define bFor(i,b,a) for(i=b,--i;i>=(ll)a;--i)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N,0)
#define brep1(i,N) bFor(i,N,1)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define endl "\n"
#define eb emplace_back
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
// const ll mod=1000000007;
const ll mod=998244353;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

int main(){
  int i,j=1,N,x;
  cin>>N>>x;
  if(x==1||x==N*2-1){
    printno;
    return 0;
  }
  printyes;
  if(N==2){
    puts("1 2 3");
    return 0;
  }
  vector<int> ans(2*N-1,0),used(2*N,0);
  if(x!=2){
    ans[N-2]=x-2;
    ans[N-1]=x;
    ans[N]=x+1;
    ans[N+1]=x-1;
    rep(i,4)used[x-2+i]=1;
  }else{
    ans[N-2]=x+2;
    ans[N-1]=x;
    ans[N]=x-1;
    ans[N+1]=x+1;
    rep(i,4)used[x-1+i]=1;
  }
  rep(i,N*2-1){
    if(!ans[i]){
      while(used[j])++j;
      ans[i]=j;
      used[j]=1;
    }
    print(ans[i]);
  }
}