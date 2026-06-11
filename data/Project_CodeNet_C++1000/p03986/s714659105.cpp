#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	string s;
	cin>>s;
	int len=s.size() ;
	if(len<2){
		cout<<len<<endl;
		return 0;
	} 
	for(int i=0;i<len-1;i++){
		if(s[i]=='S'&&s[i+1]=='T'){
			s.erase(i,2);
			len-=2;
			i-=2;
			if(i<-1)i=-1;
			len=s.size() ;
		}
	}
	cout<<s.size()<<endl;
} 