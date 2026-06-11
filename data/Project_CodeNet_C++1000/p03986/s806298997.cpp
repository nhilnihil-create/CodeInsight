#include<iostream>
#include<string>
#include<stack>
using namespace std;
const int maxn=200010;
int main(){
	stack<char> st;
	string s;
	cin>>s;
	int t=1e4;
	int sz=s.size();
	for(int i=0;i<s.size();i++){
		if(st.empty()){
			st.push(s[i]);
			continue;
		}
		if(st.top()=='S'&&s[i]=='T'){
			t--;
			st.pop();
			sz-=2;
		}
		else{
			st.push(s[i]);
		}
		//if(t==0){
		//	break;
		//}
	}
	cout<<sz<<endl;
	return 0;
}