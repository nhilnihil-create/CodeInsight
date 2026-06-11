#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int arr[n+1];
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  sort(arr, arr+n);
  arr[n] = 0;
  int top = arr[0] * 2;
  if(arr[1] == arr[0]) --top;
  if(arr[2] == arr[0] || arr[n-1] != top){
    printf("Impossible");
    return 0;
  }
  bool noo = false;
  int prev = arr[0];
  for(int i = 1; i < n; i++){
    if(arr[i] != prev){
      if(noo || arr[i]-prev > 1){
        printf("Impossible");
        return 0;
      }else{
        noo = true;
        prev = arr[i];
      }
    }else{
      noo = false;
    }
  }
  printf("Possible");
}

