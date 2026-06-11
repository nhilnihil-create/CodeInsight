#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    string s;
    cin>>n>>a>>b>>s;
    int a1=0,b1=0;
    for(int i=0;i<n;i++){
      if(s[i]=='a' && a+b>a1+b1){
        cout<<"Yes"<<endl;
        a1++;
      }
      else if(s[i]=='b' && b+a>a1+b1 && b>b1){
        cout<<"Yes"<<endl;
        b1++;
      }
      else{
        cout<<"No"<<endl;
      }
    }
  return(0);
}