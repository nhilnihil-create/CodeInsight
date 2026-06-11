#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define MOD 1000000007
using namespace std;

 ll pow(ll b){
    ll ans = 1; 
    for(int i = 1;i <= b; i++)
      ans = ((ans%MOD) * (2%MOD))%MOD;
    return ans;
 }
 
int main(){
 int n;
 cin >> n;
 ll a[n];
 int freq[100009];
 
 for(int i = 0; i < 100008; i++) freq[i]  = 0;
 
 for(int i = 0; i < n; i++){
      cin >> a[i]; 
      freq[a[i]]++;
 }
 bool res = 1;
 if(n&1){
  if(freq[0] > 1) res = 0;
  else{
   for(int i = 0 ; i < n ; i++){
	   if((freq[a[i]] != 2 && a[i] != 0) || a[i]%2 != 0){
	      res = 0;
	      break;                	   
	   }
 	 } 
   }
   res == 0? cout << "0" : cout << pow(n/2);    
 }
 else{
	 if(freq[1] != 2) res = 0;
	 else{
	  for(int i = 0 ; i < n ; i++){
	    if(freq[a[i]] != 2 || a[i]%2 == 0){
	      res = 0;
	      break;                	   
	   }
 	 } 
   }
   res == 0? cout << "0" : cout << pow(n/2); 	 
 }
 return 0;	
}
