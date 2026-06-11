#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  int n, a[100000] = {0}, x, sum;
  int i;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> x;
    a[x - 1]++;
  }
  sort(a, a + 100000, greater<int>());
  for(i = 0; i < n;){
    if(a[i] > 2){
      a[i] = a[i] - 2;
    }else if(a[i] > 1 && a[i + 1] != 0){
      a[i] = a[i] - 1;
      a[i + 1] = a[i + 1] - 1;
    }else {
      i++;
    }
  }
  for(i = 0; i < n; i++){
    if(a[i] == 1){
      sum++;
    }
  }
  cout << sum << endl;
  return 0;
}