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

int main(){
  int H, W;
  scanf("%d", &H);
  scanf("%d", &W);
  std::map<char, int > mp;
  for (int i=0; i<H; i++){
    std::string s;
    std::cin >> s;
    for (int j=0; j<W; j++){
      mp[s[j]]++;
    }
  }
  int require4 = int(H/2)*int(W/2);
  int require2 = 0;
  int require1 = 0; 
  if (H%2==1) require2+=int(W/2);
  if (W%2==1) require2+=int(H/2);
  if (H%2==1 && W%2==1) require1++;
  int enable4count = 0;
  int enable2count = 0;
  for (auto &entry: mp){
    if (enable4count>=require4) break;
    enable4count += entry.second/4;
    mp[entry.first] = entry.second%4;
  }
  for (auto &entry: mp){
    if (enable2count>=require2) break;
    enable2count += entry.second/2;
    mp[entry.first] = entry.second%2;
  }
  if (enable4count>=require4 && enable2count>=require2){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
