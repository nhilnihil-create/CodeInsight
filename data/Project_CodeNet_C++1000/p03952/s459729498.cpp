#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,k;
  cin >> n >> k;
  if(n == 2){
    if(k != 2)cout << "No" << endl;
    else {
      cout  << "Yes" << endl;
      rep(i,3)cout << i+1 << endl;
    }
    return 0;
  }
  if(k == 1 || k == 2*n-1){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  deque<int> dq;
  if(k != 2){
    dq.push_back(k);
    dq.push_back(k-1);
    dq.push_front(k+1);
    dq.push_front(k-2);
    ll l = n-3;
    int i;
    for(i = 1;i <= 2*n-1;i++){
      if(l == 0)break;
      if(abs(i-k) <= 1 || i == k-2)continue;
      dq.push_front(i);
      l--;
    }
    for(;i <= 2*n-1;i++){
      if(abs(i-k) <= 1 || i == k-2)continue;
      dq.push_back(i);
    }
  }else{
    dq.push_back(k);
    dq.push_back(k+1);
    dq.push_front(k-1);
    dq.push_front(k+2);
    ll l = n-3;
    int i;
    for(i = 1;i <= 2*n-1;i++){
      if(l == 0)break;
      if(abs(i-k) <= 1 || i == k+2)continue;
      dq.push_front(i);
      l--;
    }
    for(;i <= 2*n-1;i++){
      if(abs(i-k) <= 1 || i == k+2)continue;
      dq.push_back(i);
    }
  }
  rep(i,2*n-1){
    cout << dq.front() << endl;
    dq.pop_front();
  }


  
  


  return 0;
}