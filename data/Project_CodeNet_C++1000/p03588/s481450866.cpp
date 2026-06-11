#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


int main() {
  
  int N;
  cin >> N;

  int maxi = 0,point;
  for(int i = 0;i < N;i++) {
    int a,b;
    cin >> a >> b;
    if(maxi < a) {
      maxi = a;
      point = b;
    }
  }

  cout << maxi + point << endl;
}

