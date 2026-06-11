#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
stack<char> s;
string x;
int ans;
int main(){
	cin>>x;
	ans=x.length();
	for(int i=0;i<x.length();i++){		
		if(s.size()&&s.top()=='S'&&x[i]=='T'){
			ans-=2;
			s.pop();
			continue;
		}
		s.push(x[i]);
	}
	cout<<ans<<endl;
	 
	return 0;
	
} 