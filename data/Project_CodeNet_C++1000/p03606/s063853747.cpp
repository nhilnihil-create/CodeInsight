#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,l,r,count=0;
  cin >> n;
  
  while(n>0){
    cin >> l >> r;
    count += (r-l)+1;
    n --;
  }
  cout << count << endl;
}