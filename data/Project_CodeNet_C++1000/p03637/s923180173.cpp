#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
int sage(int n){
if(n%2==1){
  return n/2+1;
}else
{
  return n/2;
}


}
int main(){
int n;
cin>>n;
ll a[n];
int count2=0,count4=0;
rep(i,n){
  cin>>a[i];
  if(a[i]%4==0){
    count4++;
  }
  else if(a[i]%2==0){
    count2++;
  }
}
int count1=n-count2-count4;
//cout<<count1<<count2<<count4<<endl;

if(count2>0&&count1<=count4){
  cout<<"Yes"<<endl;
}else if(count2==0&&count1<=count4+1){
  cout<<"Yes"<<endl;
}
else
{
  cout<<"No"<<endl;
}


  return 0;
}
