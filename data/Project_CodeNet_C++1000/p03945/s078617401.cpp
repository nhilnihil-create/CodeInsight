#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    string s;
    cin >> s;
    int cnt=0;
    char now = s[0];
    for(int i = 1; i<s.size(); i++){
        if(s[i] != now){
            cnt++;
            now = s[i];
        }
    }
    cout << cnt << endl;
}