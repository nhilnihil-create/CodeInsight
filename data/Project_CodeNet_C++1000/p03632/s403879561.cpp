  
#include <bits/stdc++.h>
#include<vector>
#include<set>
#define ll long long
using namespace std;
  
int main() {
	
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t,a,b,c,d=0,n,m,k,sum,i,j;
       string str;
     cin>>a>>b>>c>>d;
     if(c>b)
     {
     	cout<<0<<endl;
     	return 0;
	 }
	 else 
	 {
	 	sum=min(b,d);
	 	k=max(a,c);
	 }
	cout<<max(0,(sum-k))<<endl;
    
  return 0;
}
