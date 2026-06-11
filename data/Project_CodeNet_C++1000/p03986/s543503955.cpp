#include<bits/stdc++.h>
using namespace std;
string X;
stack<int> sta;
int child=0;
int main(){
	cin>>X;
	for(int i=0;i<X.size();i++){
		if(X[i]=='S')
			sta.push(1);
		else{
			if(!sta.empty()){
				child+=2;
				sta.pop();
			}
		}
	}
	cout<<X.size()-child<<endl;
	return 0;
}
