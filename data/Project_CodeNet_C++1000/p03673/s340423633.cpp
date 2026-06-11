#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = vector<T>;
using vvi = vector<vt<int>>;

int main(){
  int n;  cin >> n;
  vt<int> a(n);
  rep(i,n){
    cin >> a[i];
  }

  int num = n - 1;
  bool f = false;
  rep(i,n){
    cout << a[num] << ' ';
    num += f ? 2 : -2;
    if(num == -2){
      f = true;
      num += 3;
    }
    else if(num == -1){
      f = true;
      ++num;
    }

  }

  cout << endl;
  return 0;
}
