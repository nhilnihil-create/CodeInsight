#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,c,s;
  cin >> n;
  vector<int> a(n);
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  c=0;
  s=0;
  for(i=0;i<n;i++){
    if(i==n-1||a.at(i)!=a.at(i+1)){
      c=1-c;
      s += c;
      c=0;
    }else{
      c=1-c;
    }
  }
  
  cout << s << endl;
}