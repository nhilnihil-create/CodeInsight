#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    string ans="EQUAL";
    if(a.length()>b.length()) ans="GREATER";
    else if(a.length()<b.length()) ans="LESS";
    else if(a.length()==b.length()){
        int n=a.length();
        for(int i=0; i<n; i++){
            if(a.at(i)-'0'>b.at(i)-'0'){
                ans="GREATER";
                break;
            }
            else if(a.at(i)-'0'<b.at(i)-'0'){
                ans="LESS";
                break;
            }
        }
    }
    cout << ans << endl;
}