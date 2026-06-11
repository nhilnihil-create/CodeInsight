#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=1;i<n;i++)
#define ll long long int

int main(){
int n;
cin>>n;
ll T,t[n];
cin>>T;
ll count=T;
cin>>t[0];
for(int i=1;i<n;i++){
cin>>t[i];
if(t[i]-t[i-1]>T){
count+=T;

}
else
{
  count+=t[i]-t[i-1];
}

}
cout<<count<<endl;



  return 0;
}
