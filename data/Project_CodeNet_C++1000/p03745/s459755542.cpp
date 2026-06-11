#include <iostream>
using namespace std; 

long long arr[1000005];

void traverse(long long n){
  int state = 0; 
  long long ans = 1; 

  for(int i = 0; i < n; i++){
    if(state == 0){ // Neutral;
      if(i == 0){
        state = 0;
      }
      else{
        if(arr[i] > arr[i - 1]){
          state = 1;
        }
        else if(arr[i] < arr[i - 1]){
          state = -1;
        }
      }
    }
    else if(state == 1){ // Ascending;
      if(arr[i] < arr[i - 1]){
        ans++; 
        state = 0; 
      }
    }
    else{ // Descending = State is -1;
      if(arr[i] > arr[i - 1]){
        ans++;
        state = 0; 
      }
    }
  }
  cout << ans << endl; 
}

int main(){
  long long n; 
  cin >> n; 

  for(long long i = 0; i < n; i++){
    cin >> arr[i];
  }
  traverse(n);
}