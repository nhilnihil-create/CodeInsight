#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000000000

int main(){
	int n;cin>>n;
	string s;cin>>s;

	int left=0,right=0;

	for(int i=0;i<n;i++){
		if(s[i]=='('){left++;}//'(':left  ')':right
		else if(s[i]==')'){
			if(left>0){left--;}//()ができている部分は足す必要なし
			else{right++;}
		}
	}

	for(int i=0;i<right;i++){//right余り分だけleft出力
		cout<<'(';
	}
	cout<<s;
	for(int i=0;i<left;i++){//left余り分だけright出力
		cout<<')';
	}
	cout<<endl;

	return 0;
}