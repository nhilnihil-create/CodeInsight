#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  
  sort(a.begin(), a.end());

  bool flag = false;
  int res = 0;
  for(int i = 1; i < N; i++){
    if(a[i] == a[i-1]){
      if(flag){
	res += 2;
	flag = false;
      }else{
	flag = true;
      }
    }
  }
  if(flag){
    res += 2;
  }
  cout << N - res << endl;
}
