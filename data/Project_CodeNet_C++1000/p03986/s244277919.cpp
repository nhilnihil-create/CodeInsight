#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string s;
	cin>>s;
	int T=0,S=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='S') S++;
		else  {
			if(S){
				S--;
			}
		}		
	 } 
	 cout<<2*S<<endl;
	return 0;
}