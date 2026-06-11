#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main(){
ll N; cin >> N; vector<ll> T(N); vector<ll> A(N);
 for(int i = 0; i < N; i++){ cin >> T[i];}
 for(int j = 0; j < N; j++){ cin >> A[j];}
  
  vector<pair<bool,bool>> asser(N);
  for(ll i = 0; i < N; i++){ asser[i].first = false; asser[i].second = false;}
                                                         
  vector<pair<ll,ll>> hight(N); //暫定的な高さを入れる
  
  hight[0].first = T[0]; asser[0].first = true;
  
  for(ll i = 1; i < N; i++){
    if(T[i] > T[i-1]){ asser[i].first = true;} //真に大きくなる時だけは断言できる
    hight[i].first = T[i];}
  
  hight[N-1].second = A[N-1]; asser[N-1].second = true;
  
  for(ll j = N - 2; j >= 0; j--){
    if( A[j] > A[j+1]){ asser[j].second = true;}
    hight[j].second = A[j];}
  
  ll cnt = 1;
  
  for(ll i = 0; i < N; i++){
    //矛盾するのは、両方とも断言できて範囲が異なるとき、ないし
    //片方は断言できているが、それがもう片方の範囲と矛盾するとき
    if( asser[i].first && asser[i].second){
      
      if( hight[i].first != hight[i].second){ cout << 0 << endl; return 0;}}
    
    else if( asser[i].first){
      
      if( hight[i].first > hight[i].second){ cout << 0 << endl; return 0;}
    }
    
    else if( asser[i].second){
      
      if( hight[i].second > hight[i].first){ cout << 0 << endl; return 0;}
    }
    
    else{ //両方とも断言できない時
      
      cnt *= min( hight[i].first, hight[i].second); cnt %= MOD;}
  }
  
  cout << cnt << endl; return 0;}
       
  