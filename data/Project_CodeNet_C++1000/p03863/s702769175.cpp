#include<iostream> 
using namespace std;
int main(){
	string s;
	cin>>s;
	int temp=0;
	if(s[0]==s[s.length()-1]){
		temp++;
	}
	if(s.length()%2==1){
		temp++;
	}
	if(temp%2==1){
		cout<<"First"<<endl;
	}else{
		cout<<"Second"<<endl;
	}
}