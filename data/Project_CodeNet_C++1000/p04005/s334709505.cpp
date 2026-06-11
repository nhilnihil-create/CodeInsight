#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<long long>arr(3);
  cin >> arr[0] >> arr[1] >> arr[2];
  if(arr[0]%2==0||arr[1]%2==0||arr[2]%2==0){
    cout << 0 << endl;
  }else{
    sort(arr.begin(), arr.end());
    long long n = arr[0]*arr[1];
    cout << n << endl;
  }
}