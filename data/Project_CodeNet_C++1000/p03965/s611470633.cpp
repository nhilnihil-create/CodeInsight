/*
   Author : tarang
*/
#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with(false); cin.tie(0);cout.tie(0);
const int MOD = 1000000007;
#define PI = acos(-1)
using namespace std ;
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main(){
	string s ;
	cin >> s ;
	int r = 1 ;
	int p = 0 ;
	int win = 0;
	if(s[0]=='p')
	 win--;
	for(int i =1 ; i < s.size() ; i++){
	     if( r > p){
	     	if(s[i] == 'g')
	     	    {
	     	    	p++;
	     	    	win++;
				 }
	     	 else {
	     	 	  p++;
			  }
		 }
		 else if(r==p){
		     r++;
			 if(s[i]=='p')
			  win--;		 	  
		 }
		
	}
	cout << win << endl;
}
