#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int N; cin >> N;
  int counter = 0;
  rep(i,N){
    int A; cin >> A;
    if (A%2 == 1) counter++;
  }  
  if(counter%2==1){
    cout << "NO" << endl;
    return 0;
  }else{
    cout << "YES" << endl;
    return 0;
  }

}