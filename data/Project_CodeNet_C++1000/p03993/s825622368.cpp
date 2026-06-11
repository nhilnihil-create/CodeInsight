#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,i;
  cin >> n;
  vector<pair<int,int>> vec(n);
  for(i=0;i<n;i++){
    int a;
    cin >> a;
    vec.at(i)=make_pair(a,i+1);
  }
  int count=0;
  for(i=0;i<n;i++){
    if(vec.at(vec.at(i).first-1).first==vec.at(i).second){
      count++;
    }
  }
  cout << count/2;
}