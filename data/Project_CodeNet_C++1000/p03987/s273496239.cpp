#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> p(n+1);
  for(int i=1;i<n+1;i++){
    int a;
    cin >> a;
    p[a] = i;
  }
  set<long long> st;
  st.insert(0);
  st.insert(n+1);
  long long ans = 0;
  for(int i=1;i<n+1;i++){
    auto r = st.lower_bound(p[i]);
    auto l = r;
    l--;
    ans += (*r - p[i]) * (p[i] - *l) * i;
    st.insert(p[i]);
  }
  cout << ans << endl;
}