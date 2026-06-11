#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;
    int len = s.length();
    vector<char> m;
    for(int i = 0; i < len; i++) {
        if(s[i] == '0' || s[i] == '1') {
            m.push_back(s[i]);
        } else {
            if(m.size() > 0)
                m.pop_back();
        }
    }
    for(auto itr = m.begin(); itr!= m.end(); itr++) {
        cout<<*itr;
    }
    cout<<endl;
    return 0;
}