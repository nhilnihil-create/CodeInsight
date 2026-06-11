#include<bits/stdc++.h>
using namespace std;
int n,a[1<<17],i;
string s;
int main(){
  cin>>n>>s;
  for(int b:{0,1}){
    for(int c:{0,1}){
      a[1]=b;
      a[2]=c;
      a[0]=(s[1]=='o')^b^c;
      for(i=3;i<n;i++)a[i]=(s[i-1]=='o')^a[i-1]^a[i-2];
      if((s[n-1]=='o')^a[n-1]==a[0]^a[n-2]&&(s[0]=='o')^a[0]==a[n-1]^a[1]){
        for(i=0;i<n;i++)cout<<(a[i]==1?'S':'W');
        cout<<endl;
        return 0;
      }
    }
  }
  cout<<-1<<endl;
}
