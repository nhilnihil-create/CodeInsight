#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF=1001001001001001001;


int main() {
  ll n,wall;
  cin>>n>>wall;
  vector<P> v(n);
  vector<ll>w1;
  vector<ll>w2;
  vector<ll>w3;
  vector<ll>w4;
  vector<ll>W1(101,0);
  vector<ll>W2(101,0);
  vector<ll>W3(101,0);
  vector<ll>W4(101,0);
  ll s1,s2,s3,s4;

  rep(i,n){
    cin>>v[i].first;
    cin>>v[i].second;
  }
  ll w=v[0].first;
  rep(i,n){
    if (v[i].first==w)w1.push_back(v[i].second);
    if (v[i].first==w+1)w2.push_back(v[i].second);
    if (v[i].first==w+2)w3.push_back(v[i].second);
    if (v[i].first==w+3)w4.push_back(v[i].second);
  }
  sort(w1.rbegin(),w1.rend());
  sort(w2.rbegin(),w2.rend());
  sort(w3.rbegin(),w3.rend());
  sort(w4.rbegin(),w4.rend());

  s1=w1.size();  s2=w2.size();
  s3=w3.size();  s4=w4.size();
  //cout<<s1<<' '<<s2<<' '<<s3<<' '<<s4<<endl;
  /*
  W1[0]=w1[0];  W2[0]=w2[0];
  W3[0]=w3[0];  W4[0]=w4[0];
*/
  rep(i,s1){
    W1[i+1]=W1[i]+w1[i];
  //  cout<<W1[i+1]<<endl;
  }
  rep(i,s2){
    W2[i+1]=W2[i]+w2[i];

  }
  rep(i,s3){
    W3[i+1]=W3[i]+w3[i];

  }
  rep(i,s4){
    W4[i+1]=W4[i]+w4[i];
  }
  ll ans=0;
rep(i,s1+1)rep(j,s2+1)rep(k,s3+1)rep(l,s4+1){
  ll wtot=(i+j+k+l)*w+j+2*k+3*l;
  //cout<<wtot<<endl;
  //cout<<i<<'i'<<j<<'j'<<k<<'k'<<l<<'l'<<endl;
  if (wtot>wall)continue;
  ll temp=W1[i]+W2[j]+W3[k]+W4[l];
//cout<<temp<<endl;
  ans=max(ans,temp);
}
cout<<ans;
return 0;
}
