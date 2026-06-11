#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=s.size();
  for(int i=1;i<n;i++){
    if((n-i)%2==1)continue;
    string t1,t2;
    t1=s.substr(0,(n-i)/2);
    t2=s.substr((n-i)/2,(n-i)/2);
    if(t1==t2){
      cout<<n-i<<endl;
      return 0;
    }
  }
}