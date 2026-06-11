#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

//const int maxn = 2 * 1e5 + 10;

int judge(string s) {
	//int mark = 0;
	stack<char>res;
	int size=s.size();
	for(int i=0;i<s.size();i++)
	{
		if(res.empty()){
			res.push(s[i]);
			continue;
		}
	    if(res.top()=='S'&&s[i]=='T'){
			res.pop();
			size=size-2;
			
		}
		else{
			res.push(s[i]);
		}
	
	}
	for(int i=1;i<=size;i++){
		char c=res.top();
		res.pop();
	}
	return size;
}


int main() {
	string s;
	cin>>s;
    cout<<judge(s)<<endl;
	return 0;
}