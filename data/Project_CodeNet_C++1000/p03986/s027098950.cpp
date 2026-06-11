#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
string X;
stack<int> sta;
int child=0;
int main(){
	cin>>X;
	int a=X.size();
	for(int i=0;i<a;i++){
		if(X[i]=='S')
			sta.push(1);
		else{
			if(!sta.empty()){
				child+=2;
				sta.pop();
			}
		}
	}
	cout<<a-child<<endl;
	return 0;
}
