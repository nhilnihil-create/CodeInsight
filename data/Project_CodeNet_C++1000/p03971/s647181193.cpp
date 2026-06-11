#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  string s;
  cin>>n>>a>>b>>s;
  int x=a+b;
  for(int i=0;i<n;i++){
    if(s[i]=='c') cout<<"No"<<endl;
    else if(s[i]=='b'){
      if(x>0 && b>0){
        cout<<"Yes"<<endl;
        x--;
        b--;
      }
      else cout<<"No"<<endl;
    }
    else{
      if(x>0){
        cout<<"Yes"<<endl;
        x--;
      }
      else cout<<"No"<<endl;
    }
  }
        
}
