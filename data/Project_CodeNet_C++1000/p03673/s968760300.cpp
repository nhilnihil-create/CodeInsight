#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
using vi = vector<int>;
int main(){
  int n;
  cin >> n;

  deque<int> b;
  rep(i,n){
    int a;
    cin >> a;
    if (i % 2 == 0) b.push_front(a);
    else b.push_back(a);
  }


  if (n % 2 == 1){
    rep(i,n){
      printf("%d ", b.front());
      b.pop_front();
    }
  }
  else {
    rep(i,n){
      printf("%d ", b.back());
      b.pop_back();
    }
  }
  printf("\n");
}
