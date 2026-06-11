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
const int INF=1000000001;
const double PI=3.141592653589;
const ll LMAX=1000000000000001;
ll gcd(ll a,ll b){if(a<b)swap(a,b);while((a%b)!=0){a=b;b=a%b;}return b;}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};



int main(){
  int h,w; cin>>h>>w;
  ll ans=LMAX;
  ll S=(ll)h*(ll)w;
  for(int i=1;i<w;i++){
    ll s1=(ll)i*(ll)h;
    ll s2=(ll)(w-i)*(ll)(h/2);
    ll s3=S-s1-s2;
    ans=min(max({s1,s2,s3})-min({s1,s2,s3}),ans);
    s2=(ll)(w-i)/2*(ll)h;
    s3=S-s1-s2;
    ans=min(max({s1,s2,s3})-min({s1,s2,s3}),ans);
  }
  for(int i=1;i<h;i++){
    ll s1=(ll)i*(ll)w;
    ll s2=(ll)(h-i)*(ll)(w/2);
    ll s3=S-s1-s2;
    ans=min(max({s1,s2,s3})-min({s1,s2,s3}),ans);
    s2=(ll)(h-i)/2*(ll)w;
    s3=S-s1-s2;
    ans=min(max({s1,s2,s3})-min({s1,s2,s3}),ans);
  }
  cout<<ans<<endl;

  return 0;
}
