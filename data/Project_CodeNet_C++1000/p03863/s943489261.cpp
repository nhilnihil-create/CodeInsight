#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define ll long long
#define rn(i,n) for(int i=1;i<=n;i++)
#define INF 1000000010

int main() {
  string s;
  cin>>s;
  if(s.at(0)==s.at(s.size()-1)){
    if(s.size()%2==1){
      cout<<"Second"<<endl;
    }else cout<<"First"<<endl;
  }else{
    if(s.size()%2==1){
      cout<<"First"<<endl;
    }else cout<<"Second"<<endl;
  }
return 0;
}
