#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin>>str;
	string anotherstr=str;
	reverse(str.begin(),str.end());
	for(int i=0;i<str.size();i++){
		if(str[i]=='b'){
			str[i]='d';
		}else
		if(str[i]=='d'){
			str[i]='b';
		}else
		if(str[i]=='p'){
			str[i]='q';
		}else
		if(str[i]=='q'){
			str[i]='p';
		}
	}
	if(str==anotherstr){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}