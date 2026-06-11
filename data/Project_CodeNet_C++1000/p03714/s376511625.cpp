#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<iostream>

using namespace std;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
const long long INF = 1LL << 60;
using ll = long long;

 
/****************************************\
| Thank you for viewing my code:)        |
| Written by RedSpica a.k.a. RanseMirage |
| Twitter:@asakaakasaka                  | 
\****************************************/
 
 
signed main() {
  ll n;
    cin>>n;
  ll sum=0;
  ll resum=0;
  vector<ll> A(3*n);
  priority_queue<ll> front;
  priority_queue<ll> back;

  for(int i=0;i<3*n;++i){
    cin>>A[i];
    if(i<n){
      front.push(-A[i]);
      sum+=A[i];
    }

    if(2*n-1<i){
      back.push(A[i]);
      resum+=A[i];
    }
  }

  vector<pair<ll,ll>> ans(n+1);
  ans[0].first=sum;
  ans[n].second=resum;
  
  for(int i=n;i<2*n;i++){
    front.push(-A[i]);
    sum+=A[i];

    ll a=front.top();
    sum+=a;
    front.pop();
    ans[i-n+1].first=sum;
  }

  for(int i=(2*n-1);n<=i;i--){
    back.push(A[i]);
    resum+=A[i];

    ll a=back.top();
    resum-=a;
    back.pop();
    ans[i-n].second=resum;
  }

  ll Ans=-INF;
  for(int i=0;i<n+1;i++){
    ll now=ans[i].first-ans[i].second;
    chmax(Ans,now);
  }
  cout<<Ans<<endl;
}