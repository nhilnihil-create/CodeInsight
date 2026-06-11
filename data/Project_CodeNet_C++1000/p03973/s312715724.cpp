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

  int n;
  cin>>n;
  vector<int64_t> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int64_t result=0;
  int64_t price=2;
  for(int i=0;i<n;i++){
    if(i==0){
      result+=a[i]-1;
    }else{
      if(price==a[i]){
        price++;
      }else{
        result+=(a[i]-1)/price;
      }
    }
  }

  cout<<result<<endl;

  return 0;
}
