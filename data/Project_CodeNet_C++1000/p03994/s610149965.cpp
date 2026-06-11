#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

using namespace std;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  string s;
  int k;
  cin>>s>>k;
  for(auto& c:s){
    if(c=='a') continue;
    int count='z'-c+1;
    if(count<=k){
      k-=count;
      c='a';
    }
  }
  s[s.size()-1]+=k%26;
  if(s[s.size()-1]>'z'){
    s[s.size()-1]-='z'-'a';
  }
  cout<<s<<endl;

  return 0;
}
