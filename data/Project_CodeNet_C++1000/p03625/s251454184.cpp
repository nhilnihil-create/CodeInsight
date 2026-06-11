#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;
int main(){
  int n;cin>>n;
  vector<int>v(n);
  rep(i,n){
    cin>>v.at(i);
  }
  sort(all(v),greater<int>());
  int a=0,b=0;
  
  rep(i,n-1){
    if(v.at(i)==v.at(i+1)){
      if(a==0){
        a=v.at(i);
        i++;
        continue;
       }
      else{
        b=v.at(i);
        break;
      }
    }
  }
  
  cout<<(ll)a*b;
}
