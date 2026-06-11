#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  set<int> st;
  int cur = 0;
  while(true){
    st.insert(cur);
    if(cur % b == c){
      cout << "YES" << endl;
      return 0;
    }
    cur += a;
    cur %= b;
    if(st.count(cur)){
      cout << "NO" << endl;
      return 0;
    }
  }
}