#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

char anti(char c){
    if(c == 'W') return 'S';
    else return 'W';
}

int main(){
    ll n;
    string s;
    cin >> n >> s;
    vector<char> a(n);
    pair<char,char> cands[4] = {{'W','W'}, {'W','S'}, {'S','W'}, {'S','S'}};
    rep(ch, 0, 4){
        a[0] = cands[ch].first;
        a[1] = cands[ch].second;
        bool tf = true;
        rep(i, 1, n-1){
            if(s[i] == 'o'){
                if(a[i] == 'S') a[i+1] = a[i-1];
                else a[i+1] = anti(a[i-1]);
            }else{
                if(a[i] == 'W') a[i+1] = a[i-1];
                else a[i+1] = anti(a[i-1]);
            }
        }
        if(a[0] == 'S'){
            if(s[0] == 'o') {
                if(a[1] != a[n-1]) tf = false; 
            }else{
                if(a[1] == a[n-1]) tf = false;
            }
        }else{
            if(s[0] == 'o'){
                if(a[1] == a[n-1]) tf = false;
            }else{
                if(a[1] != a[n-1]) tf = false;
            }
        }
        if(a[n-1] == 'S'){
            if(s[n-1] == 'o') {
                if(a[0] != a[n-2]) tf = false; 
            }else{
                if(a[0] == a[n-2]) tf = false;
            }
        }else{
            if(s[n-1] == 'o'){
                if(a[0] == a[n-2]) tf = false;
            }else{
                if(a[0] != a[n-2]) tf = false;
            }
        }
        if(tf){
            rep(i, 0, n-1) cout << a[i];
            cout << a[n-1] << endl;
            return 0; 
        }
    }
    cout << -1 << endl;
    return 0;
}