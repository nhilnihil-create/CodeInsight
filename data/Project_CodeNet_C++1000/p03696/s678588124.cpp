#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
  	cin >> n;
  	string s;
  cin >> s;
    int cnt1=0;
     int cnt2=0;
       stack<char> st;
     for(int i=0;i<n;++i){
     	if(!st.empty()){
        	if(st.top()=='(' && s[i]==')')st.pop();
          	else st.push(s[i]);
        }
         else st.push(s[i]);
     }
     while(!st.empty()){
     	if(st.top()=='(')cnt1++;
       else cnt2++;
           st.pop();
     }
     cout << string(cnt2,'(') << s << string(cnt1,')');
}
