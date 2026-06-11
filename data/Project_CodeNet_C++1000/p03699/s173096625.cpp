#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int total=0;
  int arr[n];
  for (int i=0; i<n; i++){
    cin >> arr[i];
    total+=arr[i];
  }
  sort(arr, arr+n);
  if (total%10!=0){
    cout << total << endl;
    return 0;
  }
  else{
    int max = total;
    for (int i=0; i<n; i++){
        max -= arr[i];
    	if (max%10!=0){
        	cout << max << endl;
            return 0;
        }
        max = total;
    }
    cout << 0 << endl;
  }
}
    