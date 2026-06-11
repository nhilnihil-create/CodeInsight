#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const double PI=3.141592653589;
const int INF=1000000007;
const ll LMAX=1000000000000001;
const ll mod=1000000007;
ll gcd(ll a,ll b){if(a<b)swap(a,b);while((a%b)!=0){a=b;b=a%b;}return b;}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int main(){
  int n; cin>>n;
  ll t,a; cin>>t>>a;
  rep(i,n-1){
    ll T,A; cin>>T>>A;
    ll b=t/T;
    if(t%T!=0) b++;
    ll c=a/A;
    if(a%A!=0) c++;
    ll k=max(b,c);
    t=T*k;a=A*k;
  }
  cout<<t+a<<endl;

  return 0;
}
