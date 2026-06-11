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

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  cin>>n;
  std::vector<int> a(n);
  int min=INT32_MAX,max=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    min=std::min(min,a[i]);
    max=std::max(max,a[i]);
  }
  if(max-min==0){

    bool     is_alone = true, is_notalone = true;
    for(auto x:a){
      if(x != n - 1) is_alone       = false;
      if(!(x <= n / 2)) is_notalone = false;
    }
    if(is_alone || is_notalone){
      cout << "Yes" << endl;
      return 0;
    }else{
      cout << "No" << endl;
      return 0;
    }
  }else if(max-min==1){
    int num_min = 0, num_max = 0;
    for(auto   x:a){
      if(x == min){
        num_min++;
      }else{
        num_max++;
      }
    }
    if(num_min+1<=max&&max<=num_min+num_max/2){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
    
  }else{
    cout<<"No"<<endl;
      

  }

  return 0;
}
