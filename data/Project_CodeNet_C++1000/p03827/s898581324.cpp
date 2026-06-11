#include<iostream>
using namespace std;
int main(){
	int n;
  	int sub=0;
  	int sum=0;
  	string s;
  	cin>>n>>s;
  	for(int i=0;i<n;i++){
    	if(s[i]=='I'){
          sub++;
          if(sum<sub) sum=sub; 
        }
        if(s[i]=='D') sub--;
      	
    }
  	cout<<sum<<endl;
}