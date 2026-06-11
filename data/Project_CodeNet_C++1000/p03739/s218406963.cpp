#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }

  ll ans = 0;
  ll sum = 0;
  // 最初が正
  for(int i = 0; i < N; i++){
    if(i %2 == 0){
      sum += A.at(i);
      if(sum > 0){
        //continue;
      } else { 
        ans += 1 - sum;
        sum = 1;
      }
    } else{
      sum += A.at(i);
      if(sum < 0){
        continue;
      } else { 
        ans += sum - (-1);
        sum = -1;
      }
    }
  }


  ll ans2 = 0;
  sum = 0;
  // 最初が負
  for(int i = 0; i < N; i++){
    if(i %2 == 0){
      sum += A.at(i);
      if(sum < 0){
        //continue;
      } else { 
        ans2 += sum - (-1);
        sum = -1;
      }
    } else{
      sum += A.at(i);
      if(sum > 0){
        // continue;
      } else { 
        ans2 += 1 - sum;
        sum = 1;
      }
    }
  }

  cout << min(ans, ans2) << endl;

  
}
