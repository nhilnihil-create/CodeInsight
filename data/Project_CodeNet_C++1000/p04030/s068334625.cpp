#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s.at(i)=='0' || s.at(i)=='1'){
            st.push(s.at(i));
        }else if(s.at(i)=='B'){
            if(!st.empty())
                st.pop();
        }
    }
    string ans="";
    while(true){
        if(st.empty()) break;
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}