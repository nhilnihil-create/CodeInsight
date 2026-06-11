#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    set<char> st;
    rep(i,s.size()){
        st.insert(s[i]);
    } 
    if(st.size()==4){ cout << "Yes" << endl; return 0;}
    else if(st.size()==3) { cout << "No" << endl; return 0;}
    else if(st.size()==2){
        if((st.count('N')==1) && (st.count('S')==1)) { cout << "Yes" << endl; return 0;}
        if((st.count('W')==1) && (st.count('E')==1)) { cout << "Yes" << endl; return 0;}
        else cout << "No" << endl;
    }
    else cout << "No" << endl;

    return 0;
}