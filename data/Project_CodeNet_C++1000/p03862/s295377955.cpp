#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,x;
  cin>>n>>x;
  vector<int >nos(n,0);
  for(int i=0;i<n;i++)cin>>nos[i];
  long long mini=0,ny=0;
  for(int i=0;i<n-1;i++){
  if(nos[i]>x){mini+=(nos[i]-x);nos[i]=x;}
    if(nos[i]+nos[i+1]>x){
    	ny = x-nos[i];
      	mini+=(nos[i+1]-ny);
      	nos[i+1]=ny;
          
    }
  }
  cout<<mini;
}