#include <iostream>
#include <cstdlib>

using namespace std;

int a[100000];
int n;
int cnt = 1;

int botton(int x){
  if(cnt > n) {
    return -1;
  }
  if(a[x] == 2) {
    return cnt;
  } else {
    cnt++;
    return botton(a[x]);
  }
}


int main(){
  cin >> n;
  for(int i = 1; i < n+1; i++){
    cin >> a[i];
  }
  cout << botton(1) << endl;
  return 0;
}
