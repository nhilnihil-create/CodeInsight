#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    string t="CODEFESTIVAL2016";
    int count=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]!=t[i]) {
            count++;
        }
    }
    cout<<count<<endl;
}