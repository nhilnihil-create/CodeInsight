#include<bits/stdc++.h>

using namespace std;

int main(void){
  int n;
  cin >> n;
  int count = 0;
  int count2 = 0;
  
  for(int i = 0;i < n;i++){
    int x; cin >> x;
    if(x % 4 == 0) count++;
    else if(x % 2 == 0) count2++;
  }
  
  cout << (count+count2/2 >= n/2 ? "Yes" : "No") << endl;
}