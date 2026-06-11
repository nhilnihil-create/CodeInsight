#include<bits/stdc++.h>
using namespace std;

int main(){
  map<int,int>a;
  int n;
  for(int i=0;i<3;i++){
    cin >> n;
    a[n]+=1;
  }
  n=0;
  for(auto x:a)
    n++;
  cout << n << endl;
}