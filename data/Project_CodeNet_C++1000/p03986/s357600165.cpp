#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    string x;
    cin>>x;
    stack<char> st;
    rep(i, x.size()){
        if(x[i] == 'S'){
            st.push('S');
        }
        else {
            if(st.size() == 0){
                st.push('T');
            }
            else{
                if(st.top() == 'S') st.pop();
                else st.push('T');
            }
        }
    }
    cout<<st.size()<<endl;
    return 0;
}