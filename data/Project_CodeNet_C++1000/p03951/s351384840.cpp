#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;string s,t;cin>>n>>s>>t;
  int maxi=0;
  for(int i=0;i<n;i++){//going through all substrings starting from 0 in t
   for(int start=0;start<n;start++)//starting pos in s
   {
     int ans=0;
  		for(int j=0;j<=i;j++){
          if(start+j >=n)break;
        	if(s[start+j]==t[j])ans++;
        }
    maxi = max(maxi,ans);
  	} 
  }
cout<<n-maxi+n;
    //for(int i=0;i<n-maxi;i++)cout<<s[i];
    //cout<<t;
}