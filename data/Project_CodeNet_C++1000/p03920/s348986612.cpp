#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;

  ll sum = 0LL;
  int ind;
  for(int i=1;i<=N;i++){
    sum += i;
    if(sum >= N){
      ind = i;
      break;
    }
  }

  int x = sum - N;
  for(int i=1;i<=ind;i++){
    if(i != x) cout << i << endl;
  }

  return 0;
}