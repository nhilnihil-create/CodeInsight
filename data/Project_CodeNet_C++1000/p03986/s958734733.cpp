#include<iostream>
#include<string>
#include <stack>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(i==0)
            st.push(s[i]);
        else{
            if(!st.empty()&&st.top()=='S'&&s[i]=='T'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    cout<<st.size();
    return 0;
}

