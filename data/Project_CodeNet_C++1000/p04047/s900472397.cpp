#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin >> n;
  vector<int> hash(2*n);
  for(int i = 0; i < 2*n ; i++){
    cin >> x;
    hash[i] = x;
  }
  sort(hash.begin(),hash.end());
  int sum = 0;
  for(int i = 0; i<2*n ; i+=2){
    sum = sum + hash[i];
  }
  cout<<sum;
}