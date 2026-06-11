#include<iostream>
#include<string>
using namespace std;
int n,line[100000];
string s;
void co(){
	for(int i=0;i<n;i++){
		if(line[i]==0)cout<<"S";
		else cout<<"W";
	}
	return ;
}
int main(void){
	cin>>n>>s;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			line[0]=i;
			line[1]=j;
			for(int k=1;k<n-1;k++){
				if((line[k]==0&&s[k]=='o')||(line[k]==1&&s[k]=='x'))line[k+1]=line[k-1];
				else line[k+1]=!line[k-1];
			}
			if(line[0]==0){
				if(s[0]=='o')if(line[1]!=line[n-1])continue;
				if(s[0]=='x')if(line[1]==line[n-1])continue;
			}
			else{
				if(s[0]=='o')if(line[1]==line[n-1])continue;
				if(s[0]=='x')if(line[1]!=line[n-1])continue;
			}
			if(line[n-1]==0){
				if(s[n-1]=='o')if(line[0]!=line[n-2])continue;
				if(s[n-1]=='x') if(line[0]==line[n-2])continue;
			}
			else{
				if(s[n-1]=='o')if(line[0]==line[n-2])continue;
				if(s[n-1]=='x')if(line[0]!=line[n-2])continue;
			}
			co();
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}