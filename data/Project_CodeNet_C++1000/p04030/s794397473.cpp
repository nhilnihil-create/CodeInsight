#include<iostream>
#include<bits/stdc++.h>

using namespace std;



int main(){
	stack<char> box;
	string S;
	cin>>S;

	for(int i=0;i<S.length();i++){
		if(S[i]=='B'){
			if(box.empty()==false){
				box.pop();
			}
		}
		else{
			box.push(S[i]);
		}

	}

string ans;
while(box.empty()==false){
	ans+=box.top();
	box.pop();
}
reverse(ans.begin(),ans.end());
cout<<ans<<endl;

}

