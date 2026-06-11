#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  ll a,b;
  cin>>a>>b;
  if(a>0&&b>0){
    cout<<"Positive"<<endl;
  }
  if(a<=0&&b>=0){
    cout<<"Zero"<<endl;
  }
  if((a<0&&b<0)&&(b-a)%2==0){
    cout<<"Negative"<<endl;               
  }      
  if((a<0&&b<0)&&(b-a)%2==1){
    cout<<"Positive"<<endl;               
  }      
}   