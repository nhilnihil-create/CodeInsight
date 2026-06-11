#include <bits/stdc++.h>

using namespace std;

int main() {
    string s , a = "" , b = "";
    cin>>s;
    for(int i = 0 ; i < 12; ++i){
        if(i < 4){
            a += s[i];
        }else b += s[i];
    }
    cout<<a<<" "<<b<<"\n";
}