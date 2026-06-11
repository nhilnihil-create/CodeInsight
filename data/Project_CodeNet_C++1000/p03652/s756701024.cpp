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

int main(void){
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;
  std::vector<int> like[310];
  for(int i=0;i<n;i++){
    like[i].resize(m+1);
    for(int j=m;j>=1;j--){
      int a;
      cin>>a;
      like[i][a]=j;
    }

  }

  int result=n;
  bool omitted[310]={};
  for(int i=1;i<=m;i++){
    int contestants[310]={};
    for(int j=0;j<n;j++){
      const std::vector<int>& person=like[j];
      int join_id=-1;
      int max_like=0;
      for(int k=1;k<=m;k++){
        if(!omitted[k]){
          if(max_like<person[k]){
            max_like=person[k];
            join_id=k;
          }
        }
      }
      if(join_id==-1){
        cout<<result<<endl;
        return 0;
      }
      contestants[join_id]++;
    }

    int max_contestants=0;
    std::vector<int> omit_id;
    for(int j=1;j<=m;j++){
      if(max_contestants<contestants[j]){
        omit_id.clear();
        omit_id.push_back(j);
        max_contestants=contestants[j];

      }else if(max_contestants==contestants[j]){
        omit_id.push_back(j);
      }
    }
    if(max_contestants>0){
      result=std::min(max_contestants,result);
    }

    for(auto o:omit_id){
      omitted[o]=true;
    }
  }
  cout<<result<<endl;


  
  return 0;
}
