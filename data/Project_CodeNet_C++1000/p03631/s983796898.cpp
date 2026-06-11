  
#include <bits/stdc++.h>
#include<vector>
#include<set>
#define ll long long
using namespace std;
  
int main() {
	
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t,a,b,c,d=0,n,m,k,sum=1,i,j;
       string str;
    cin>>str;
    n=str.size();
    for(i=0,j=n-1;i<j;i++,j--)
    {
    	if(str[i]!=str[j])
    	{
    		cout<<"No\n";
    		return 0;
		}
	}
	cout<<"Yes\n";
	
    
  return 0;
}
