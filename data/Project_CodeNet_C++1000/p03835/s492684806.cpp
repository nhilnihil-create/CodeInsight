#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
 int k , s;
 int ans = 0;
 cin >> k >> s;
 for(int i = 0; i <= k; i++){
    for(int j = 0; j <= k; j++){
	    if(s - (i + j) <= k && (i + j <= s)) ans++;
	    //cout << i << " " << j << "\n";
	   //for(int z = 0; z <= k; z++){
		      //if(i + j + z == s) ans++;   
		   //}
	  }	 
 }	
 cout << ans << " ";	
 return 0;	
}