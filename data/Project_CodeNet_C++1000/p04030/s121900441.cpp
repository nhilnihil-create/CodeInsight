#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    vector<char> a(s.size());
    for(int i = 0; i < s.size(); i++) {
        a[i]=s[i];
    }

    int b=0;
    for(int i = 0; i < s.size(); i++) {
        if(s[s.size()-1-i]=='B'){
            b++;
        }
        else{
            if(b>0){
                a[s.size()-1-i]='A';
                b--;
            }
        }
    }

    for(int i = 0; i < s.size(); i++) {
        if(a[i]=='1') cout << 1;
        if(a[i]=='0') cout << 0;
    }
    cout << endl;

    return 0;
}