#include <bits/stdc++.h>
using namespace std;

int main () {
	string s;
	
	cin>>s;
	
	sort(s.begin(), s.end());
	
	int x = s.length();
	
	if(x==1){
		cout<<"No"<<endl;
		return 0;
	}
	int sum =1;
	for(int i=1; i<x; i++){
		if(s[i] == s[i-1]){
			sum++;
		} else {
			if(sum%2!=0) {
				cout<<"No"<<endl;
				return 0;
			}
			sum=1;
		}
		
		if(i==x-1 && s[i] == s[i-1]){
			if(sum%2==0){
				cout<<"Yes"<<endl;
				break;
			} else {
				cout<<"No"<<endl;
				break;
			}
		} else if(i==x-1 && s[i] != s[i-1]){
			cout<<"No"<<endl;
			break;
		}
	}
}