#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;
typedef long long ll;


int main(){
  ll N,A,B;
  cin >> N >> A >> B;
  
  if(A>B){
    cout << 0 << endl;
    return 0;
  }
  
  if(N==1){
    if(A==B)
      cout << 1 << endl;
    else
    	cout << 0 << endl;
    return 0;
  }
  
  cout << (B-A)*(N-2)+1 << endl;
  
}