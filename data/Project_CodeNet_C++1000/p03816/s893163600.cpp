#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;cin>>n;
  int an[100100];rep(i,100100) an[i]=0;
  int a;
  rep(i,n) {
    cin>>a;
    an[a] ++;
  }
  int uni=0, dup=0;
  rep(i,100100) {
    if (an[i] > 0) {
      uni++;
      if (an[i]>1) dup += an[i]-1;
    }
  }
  uni -= dup%2;
  cout << uni;
}
