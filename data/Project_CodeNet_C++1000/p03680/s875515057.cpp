#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, bangou, kaisu; bool a=false;
  cin>>n; vector<int> nums(n);
  for(int i=0; i<n; i++){
    cin>>nums.at(i);
  }
  for(int i=0; i<n; i++){
    if(i==0){bangou=nums.at(i);}else{bangou=nums.at(bangou-1);} kaisu++;
    if(bangou==2){a=true; cout<<kaisu<<endl; break;}
  }
  if(a==false){cout<<"-1"<<endl;}
}