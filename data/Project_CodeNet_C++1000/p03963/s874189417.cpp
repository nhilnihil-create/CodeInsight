#include <bits/stdc++.h>
using namespace std;

int main(){
int n,k;
  cin >> n >> k;

long long t;
  if(n==1)cout << k << endl;
  else{
    t=k;
  for(int i=1;i<n;i++){
    t*=k-1;
  }
    cout << t << endl;
  }

}