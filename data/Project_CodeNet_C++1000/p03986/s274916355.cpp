#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    string s;   cin >> s;
    stack<char> st;
    int n=s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='S') st.push('S');
        else if(st.size()>0 && st.top()=='S') st.pop();
        else st.push('T');
    }
    cout << st.size() << endl;
}

