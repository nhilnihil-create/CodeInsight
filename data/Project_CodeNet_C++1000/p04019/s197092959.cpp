#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  std::string s;
  std::cin >> s;

  vt<std::pair<bool,bool>> ans(2);
  rep(i,s.size()) {
      if(s[i] == 'N')
        ans[0].first = true;
      else if(s[i] == 'W')
        ans[1].second = true;
      else if(s[i] == 'S')
        ans[0].second = true;
      else
        ans[1].first = true;
  }

  if(ans[0].first == ans[0].second && ans[1].first == ans[1].second)
    std::cout << "Yes" << '\n';
  else
    std::cout << "No" << '\n';
  return 0;
}
