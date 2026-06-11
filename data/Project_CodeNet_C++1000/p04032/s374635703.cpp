#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;
    int len = s.length();
    int flag = 0;
    for(int i = 0; i < len-1; i++) {
        if(s[i] == s[i+1]) {
            cout<<i+1<<" "<<i+2;
            flag = 1;
            break;
        } else if( s[i] == s[i+2]) {
            cout<<i+1<<" "<<i+3;
            flag = 1;
            break;
        }
    }
    if(!flag) {
        cout<<-1<<" "<<-1;
    }
    cout<<endl;
    return 0;
}