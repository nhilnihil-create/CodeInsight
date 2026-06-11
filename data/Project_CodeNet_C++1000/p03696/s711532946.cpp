#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin>>N>>S;
    stack<char> st;
    st.push('N');

    for(int i=0; i<N; i++){
        char pr =  st.top();
        if((S[i] == ')' && pr == '(')){
            st.pop();
        }
        else{
            st.push(S[i]);
        }
    }

    map<char,int> cnt;
    while(!st.empty()){
        char t = st.top();
        st.pop();
        cnt[t]++;
    }

    string ans = "";
    for(int i=0; i<cnt[')']; i++) ans += '(';
    ans += S;
    for(int i=0; i<cnt['(']; i++) ans += ')';

    cout<<ans<<endl;
}