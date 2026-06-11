#include <iostream>
#include<string>
using namespace std;
int check(string &st,bool arr[]){
	for(int i=0;i<st.length();i++){
		if(arr[st[i]-'0']==true)return false;
	}
	return true;
}
int main() {
	int n,k;
	cin>>n>>k;
	bool arr[11]={};
	int x;
	for(int i=0;i<k;i++){
		cin>>x;
		arr[x]=true;
	}
	for(int i=n;i<100000;i++){
		string s=to_string(i);
		if(check(s,arr)==true){
			cout<<s;
			break;
		}
	}
}