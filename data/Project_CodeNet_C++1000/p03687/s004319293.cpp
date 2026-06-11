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
#include <set>
#include <deque>
int main(){
  std::string s;
  std::cin >> s;
  std::map<char, int > mp;
  for (int i=0; i<s.length(); i++){
    mp[s[i]]++;
  }

  int ans = 1e7;
  for (auto &entry : mp){
    int temp = 0;
    std::vector<int > pos;
    pos.push_back(-1);
    for (int i=0; i<s.length(); i++){
      if (s[i]==entry.first){
        pos.push_back(i);
      }
    }
    for (int j=0; j<pos.size()-1; j++){
      temp = std::max(temp, pos[j+1]-pos[j]-1);
    }
    temp = std::max(int(s.length())-pos[pos.size()-1]-1, temp);
    ans = std::min(ans, temp);
  }
  
  std::cout << ans << std::endl;
  return 0;
}
