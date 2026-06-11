#include<bits/stdc++.h>
using namespace std;
int main(){
  	int n,a,b;cin>>n>>a>>b;
	string s;cin>>s;
  
  int pass=0;int num_over_pass=0;
  //pass<a+b,num_over_pass<b
  for(int i=0;s[i]!='\0';i++){
  	if(s[i]=='c'){cout<<"No"<<'\n';continue;}
    if(s[i]=='a'){
    	//japansee
      	if(pass<(a+b)){
        	pass+=1;
          	cout<<"Yes"<<'\n';
        }
      	else cout<<"No"<<'\n';
    }
    else{
    	if(num_over_pass<b){
        	if(pass<(a+b)){
            	pass+=1;
              	num_over_pass+=1;
              cout<<"Yes\n";
            }
          else cout<<"No\n";
        }
      	else cout<<"No\n";
    }
  }
}