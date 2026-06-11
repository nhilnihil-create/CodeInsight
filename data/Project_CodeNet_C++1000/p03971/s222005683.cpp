#include <iostream>
#include <string>

using namespace std;

int main(){


	int n,a,b;
	string s;
	cin>>n>>a>>b;
	cin>>s;
	
	int pass=0;
	int os=0;

	for(int i=0;i<n;i++){
	
		if(s[i]=='a'){
		
			if(pass<a+b){
			
				cout<<"Yes"<<"\n";
				pass++;
			}
			else{
			
				cout<<"No"<<"\n";
			}
		}
	     else	if(s[i]=='b'){
		
			os++;
			
			if(pass<a+b&&os<=b){

				cout<<"Yes"<<"\n";
				pass++;

			}
			else{
			
				cout<<"No"<<"\n";
			}
		}
		else{
		
			cout<<"No"<<"\n";
		}
	}
	return 0;
}
