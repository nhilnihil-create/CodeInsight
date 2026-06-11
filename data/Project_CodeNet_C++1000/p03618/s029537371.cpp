#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>

int main(){
  std::string s;
  std::cin >> s;
  int n=s.length();
  long long ans = (long long)n*(n-1)/2;
  std::map<char, int > mp;
  for (int i=0; i<n; i++){
    mp[s[i]]++;
  }
  for (auto &entry: mp){
    ans -= (long long)(entry.second-1)*entry.second/2;;
  }
  ans++;
  std::cout << ans << std::endl;
  return 0;
}