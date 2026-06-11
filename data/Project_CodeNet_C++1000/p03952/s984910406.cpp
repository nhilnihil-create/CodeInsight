#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 1000000000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

int main(){
  ll N,X;
  cin >> N >> X;
  vector<ll> ans(2*N-1);
  for(int i = 0;i < 2 * N - 1;i++){
    ans[i] = i + 1;
  }
  if(X == 1 || X == 2 * N - 1){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if(N == 2){
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
  }else{
    if(X == 2){
      swap(ans[N],ans[1]);
      swap(ans[N-1],ans[0]);
    }else{
      swap(ans[N],ans[X]);
      swap(ans[N-2],ans[X-2]);
      swap(ans[N-1],ans[X-1]);
      
      swap(ans[N+1],ans[X-3]);
    }
    for(int i = 0;i < 2 * N - 1;i++){
      cout << ans[i] << endl;
    }
  }
}