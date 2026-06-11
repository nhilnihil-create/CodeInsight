#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const int INF = 1000000000;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int l = -1, r = -1;
    
    for(int i = 2; i < n; i++){
        set<char> st;
        st.insert(s[i - 2]);
        st.insert(s[i - 1]);
        st.insert(s[i]);
        if((int)st.size() < 3){
            l = i - 1;
            r = i + 1;
        }
    }
    if(n == 2){
        if(s[0] == s[1])l = 1, r = 2;
    }
    cout << l << " " << r << endl;
}