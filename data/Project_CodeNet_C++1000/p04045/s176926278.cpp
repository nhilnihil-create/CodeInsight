#include <iostream>
#include<string>
using namespace std;
int has_no(string &s,bool arr[]){
	for(int i=0;i<s.length();i++){
		if(arr[s[i]-'0']) return false;
	}
	return true;
}
int main() {
	// your code goes here
	int N,K;
	cin>>N>>K;
	bool arr[10]={};
	for(int i=0;i<K;i++){
		int n;
		cin>>n;
		arr[n]=true;
	}
	for(int i=N;i<100000;i++){
		string s=to_string(i);
		if(has_no(s,arr)){
			cout<<s<<endl;
			break;
		}
	}
	return 0;
}