#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

 long long  n,T,t,x,sum=0;
 cin>>n>>T;

 long long ani[300000];

 for(int i=0;i<n;i++)
    cin>>ani[i];

  for(int i=0;i<n-1;i++){
    sum += min(T,ani[i+1]-ani[i]);
 }


 sum  = sum +  T;
 
 cout<<sum<<endl;


return 0;
}













