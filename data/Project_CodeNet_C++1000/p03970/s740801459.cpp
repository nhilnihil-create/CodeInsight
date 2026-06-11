#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t="CODEFESTIVAL2016";
    cin >> s;
    int ans=0;
    for(int i=0;i<16;i++){
        if(s.at(i)!=t.at(i)){
            ans++;
        }
    }
    cout << ans << endl;
}