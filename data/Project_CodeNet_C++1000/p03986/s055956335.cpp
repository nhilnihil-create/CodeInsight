#include<iostream>
#include<stack>
using namespace std;

stack<char> st;
int main(){
    string s;
	cin>>s;
	int ans=s.size();
	for(int i=0;i<(int)s.size();i++){
		if(!st.empty()&&st.top()=='S'&&s[i]=='T'){
			ans-=2;
			st.pop();
		}
		else
		st.push(s[i]);
	}
	cout<<ans<<endl;
	return 0;

}