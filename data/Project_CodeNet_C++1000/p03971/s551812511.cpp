#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b;cin>>n>>a>>b;
	string s;cin>>s;
	int pass=0,bpass=0;
	for(int i=0;i<n;i++){
		if(s[i]=='a'){
			if(pass<a+b){
				cout<<"Yes"<<endl;
				pass++;
			}else{
				cout<<"No"<<endl;
			}
		}else if(s[i]=='b'){
			if(pass<a+b&&bpass<b){
				cout<<"Yes"<<endl;
				pass++;bpass++;
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}