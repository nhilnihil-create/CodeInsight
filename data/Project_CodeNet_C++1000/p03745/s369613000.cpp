#include <bits/stdc++.h>

#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )

using namespace std;

int main() {
  int n;  
  cin>>n;
 vector<int> a(n);

  rep(i,n) {cin>>a[i];}
  int ans=0;
   ////////////
  bool hueru=false,heru=false;
  rep(i,n-1){
        
   	if(!heru&&a[i]<a[i+1]){
     	hueru=true;
     continue;
   	}
   	if( hueru&&a[i]>a[i+1]){
  		
       	   ans++;
    	 hueru=false;
     	continue;
     	   }
   
   	if(a[i]>a[i+1]){
    	 heru=true;
      continue;
  	}
  	if( heru&&a[i]<a[i+1]){
  		
    	      ans++;
    	 heru=false;
    	 continue;
     	   }
    
  }  
  
  
  
  ans++;
  
  cout<<ans<<endl;
}