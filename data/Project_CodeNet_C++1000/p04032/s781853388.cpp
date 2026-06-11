#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    int flg=0;
    cin >> s;
    for(int i=1;i<(int)s.size();i++){
        if(s[i-1]==s[i]){
            cout << max(i-1,1) << ' ' << i+1 << endl;
            flg=1;
            break;
        }
        if(i>=2 && s[i-2]==s[i]){
            cout << i-1 << ' ' << i+1 << endl;
            flg=1;
            break;
        }
    }
    if(flg==0) cout << -1 << ' ' << -1 << endl;
}