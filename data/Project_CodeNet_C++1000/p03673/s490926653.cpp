#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,b,swp = 0;
  cin >> N;
  vector<long long> x;
  vector<long long> y;
  vector<long long> result;
  froop1(0,N){
    cin >> b;
    if(i % 2 == 0){
      x.push_back(b);
    }else{
      y.push_back(b);
    }
  }
  for(int i = x.size() - 1;i >= 0;i--) result.push_back(x.at(i));
    for(int i = 0;i < y.size();i++) result.push_back(y.at(i));
  if(N % 2 != 0){
  froop1(0,N){
    cout << result.at(i);
    if(i != N - 1) cout << " ";
      else         cout << endl;
   }
  }else{
      for(int i = N - 1;i >= 0;i--){
    cout << result.at(i);
    if(i != 0) cout << " ";
      else         cout << endl;
   }
  }
  return 0;
}