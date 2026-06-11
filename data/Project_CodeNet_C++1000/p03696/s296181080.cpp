#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,now=0,out=0;
    cin >> N;
    string S,ans;
    cin >> S;
    stack<char> st;
    ans = S;
    for(int i=0;i<N;i++){
        if(S[i]=='('){
            st.push('(');
        }else{
            if(st.empty()){
                ans.insert(now,"(");
            }else{
                st.pop();
            }
        }
    }

    for(int i=0;i<st.size();i++){
        ans += ')';
    }

    cout << ans << endl;
}