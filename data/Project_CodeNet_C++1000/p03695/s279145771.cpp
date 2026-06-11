#include <iostream>
using namespace std;

int main() {
  int colo[9]={};
  int n;
  cin>>n;
  int arr[n];
  for (int i=0; i<n; i++){
    cin >> arr[i];
  }
  for (int i=0; i<n; i++){
    for(int j = 0; j <=7;j++){
      if(400 * j <=arr[i] && arr[i] < 400 * (j + 1))colo[j]++;
    }
if(arr[i] >= 3200)colo[8]++;
  }
  int total=0;
  for (int i=0; i<8; i++){
    if (colo[i]>0) total++;
  }
  if ( total>0 ) cout << total << ' ' << total+colo[8] << endl; 
  else cout << 1 << ' ' << colo[8] << endl; 
return 0;
}

