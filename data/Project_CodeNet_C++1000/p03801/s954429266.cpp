#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[100005]={0};
int main(){
  ll n;
  cin>>n;
  vector<ll> vec,cos,cnt,pos;
  vec.push_back(0);
  cos.push_back(0);
  cnt.push_back(0);
  pos.push_back(0);
  ll max_val=0;
  for(int i=1;i<=n;i++){
    ll a;
    cin>>a;
    if(a>max_val) {
      vec.push_back(a);
      cos.push_back(0);
      cnt.push_back(0);
      pos.push_back(i);
      max_val=a;
    }
    int pos=lower_bound(vec.begin(),vec.end(),a)-vec.begin();
    cnt[pos-1]++;
    cos[pos]+=a-vec[pos-1];
  }
  ll k=vec.size();
  for(int i=k-1;i>0;i--){
    cnt[i-1]+=cnt[i];
  }
  for(int i=1;i<k;i++){
    ans[pos[i]]=(vec[i]-vec[i-1])*cnt[i]+cos[i];
  }
  for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
}
