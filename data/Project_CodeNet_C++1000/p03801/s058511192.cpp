#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll cnt[101010];
pair<ll,int> P[101010];

int main(){
  int N; cin>>N;
  map<ll,int> mp;
  rep(i,N){
    ll a; cin>>a;
    P[i]=make_pair(a,-(i+1));
    mp[a]++;
  }
  sort(P,P+N);
  reverse(P,P+N);
  P[N]=make_pair(0,-N);
  int ind=0;
  ll sum=0;
  while(ind<N){
    ll f=P[ind].first;int s=-P[ind].second;
    sum+=mp[f];
    int next=min(N,ind+mp[f]);
    ll f2=P[next].first;int s2=-P[next].second;
    cnt[s]+=max(1LL,f-f2)*sum;
    if(s<s2) P[next]=make_pair(f2,-s);
    ind=next;
  }
  for(int i=1;i<=N;i++) cout<<cnt[i]<<endl;
  return 0;
}
