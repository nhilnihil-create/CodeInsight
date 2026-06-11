#include<bits/stdc++.h>

using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long int a,b,c;
  cin>>a>>b>>c;
  int t=1000;
  int f=0;
  while((a%2==0 && b%2==0 && c%2==0) && t--){
    long long int x=a/2;
    long long int y=b/2;
    long long int z=c/2;
    a=y+z;
    b=x+z;
    c=x+y;
    f++;
  }
  if(f!=1000){
    cout<<f<<endl;
  }else{
    cout<<-1<<endl;
  }




}