#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  long long n, a, b;
  cin >> n >> a >> b;
  if(a>b){
    cout << 0 << endl;
    return 0;
  }
  if(n==1){
    if(a==b)cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  }
  if(n==2){
    cout << 1 << endl;
  }
  cout << (n-2)*(b-a)+1 << endl;
}
