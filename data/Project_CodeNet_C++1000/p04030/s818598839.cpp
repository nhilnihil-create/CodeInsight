#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    stack<char> st;
    int n = s.size();
    
    for (int i = 0; i < n; i++){
        
        if (s[i] == 'B'){
            if (st.empty()) continue;
            else st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    
    string ans = "";
    while (!st.empty()){
        char temp = st.top();
        st.pop();
        ans = temp + ans;
    }
    cout << ans << endl;
}