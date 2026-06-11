#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;

  cin >> n;


  vector<int> tmp;

  int tmp2 = 0;

  int i = 1;
  while(tmp2 <= 10000000){
    tmp2 += i;
    tmp.push_back(tmp2);
    i++;
  }

  while(n > 0){
    i = lower_bound(tmp.begin(),tmp.end(),n) - tmp.begin();
    i++;
    n -= i;
    cout << i << endl;
  }

  return 0;


}



