#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 
int main(){
  int n;
  cin >> n;
  int even=0, odd=0, t4=0;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    if(a%4==0){
      t4++;
      continue;
    }
    if(a%2==0){
      even++;
    }else{
      odd++;
    }
  }
  if(even>0) odd++;
  if(t4+1<odd){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
  return 0;
}