#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,k;cin>>n>>k;
vector<ll> a(n);
ll sum=0;
for(int i=0;i<n;i++){
  cin>>a[i];
  sum+=a[i];
}
//良い集合を作る
sort(all(a),greater<ll>());
ll res=0;
//組み合わせて作れる数字かの判定
vector<bool> dp(k,false);
dp[0]=true;
for(int i=0;i<n;i++){
  bool ok=false;
  //kを超える、あるjがあるか判定を行う
  for(int j=0;j<k;j++){
    ok=(dp[j]&&sum+j>=k);
    if(ok)break;
  }
  if(!ok)res++;
  else{
    sum-=a[i];
    for(int j=k-a[i]-1;j>=0;j--){
      //j+a[i]が作れるかの判定
      dp[j+a[i]]=(dp[j+a[i]]|dp[j]);
    }
  }
}
cout<<res<<endl;
}
