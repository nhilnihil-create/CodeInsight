#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int nums[100010];
int main(){
  int n;
  cin >> n;
  rep(i,n){
    int tmp;
    cin >> tmp;
    nums[tmp]++;
  }
  int ans = 0;
  int mx = 0;
  for (int i = 1; i <= 100000;i++){
    if (mx < nums[i-1] + nums[i] + nums[i+1]){
      ans = i;
      mx = nums[i-1] + nums[i] + nums[i+1];
    } 
  }
  cout << mx << endl;
 

  return 0;
}
