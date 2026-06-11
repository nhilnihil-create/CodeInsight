#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000005];

void findMax(long long n){
  long long left = 0;
  long long right = 3*n - 2; 

  long long ans = 0; 

  while(left<right){
    ans += arr[right];
    left++;
    right = right - 2; 
  }
  
  cout << ans << endl; 
}

int main(){
  long long n; 
  cin >> n; 

  for(long long i = 0; i < 3*n; i++){
    cin >> arr[i];
  }
  sort(arr , arr + 3*n);

  if(n == 1){
    cout << arr[1] << endl; 
    exit(0);
  }

  findMax(n);
}
  