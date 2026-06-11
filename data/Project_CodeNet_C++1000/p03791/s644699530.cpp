#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int n;

int main(){
  ll mod = 1e9+7;
  vector<int> x;
  cin >> n;
  for(int i = 0; i < n; i++){
      int zzz; cin >> zzz;
      x.push_back(zzz);
  }

  int condition = 1;
  int count = 0;
  ll result = 1;
  while(count < n){
    if(x[count] >= 2*condition - 1){
      condition++;
      count++;
    }
    else{
      result = (result * condition) % mod;
      count++;
    }
  }

  condition--;
  while(condition > 0){
    result = (result * condition) % mod;
    condition--;
  }

  cout << result << endl;

}
