#include<iostream>
#include<string>
using namespace std;
int main(){

 unsigned int n,a,b,i,no_of_passed=0,no_overseas=0;
 string s;
 cin>>n>>a>>b;
 cin>>s;

 for(i=0;i<n;i++){
   
   if(s[i]=='c')
    {cout<<"No";}
   else{
	   
	   if(s[i]=='a'){
		   
		   if(no_of_passed<(a+b)){no_of_passed++;cout<<"Yes";}
		   else cout<<"No";
		   }
		   
	   else{
		   if(no_of_passed<(a+b)&&no_overseas+1<=b){
			   no_of_passed++;no_overseas++;cout<<"Yes";
			   }
		   else cout<<"No";
		   }
	   
	   }
	   cout<<'\n';
 }


}
