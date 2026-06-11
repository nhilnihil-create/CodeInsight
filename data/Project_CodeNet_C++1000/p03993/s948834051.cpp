#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int a;
  cin >> a;
  vector<int> arr(a);
  rep(i,a){
    cin >> arr[i];
  }
  int sum = 0;
  rep(i,a){
  if(arr[arr[i]-1] == i+1) sum++;
  }
  cout << (sum/2) << endl;
}