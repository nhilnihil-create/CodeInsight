#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    string ans = "SS";
    {
        for(int i = 1; i < n; ++i){
            if(ans[i] == 'S'){
                if(s[i] == 'o'){
                    ans += ans[i-1];
                }
                else{
                    if(ans[i-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
            }
            else{
                if(s[i] == 'o'){
                    if(ans[i-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
                else{
                    ans += ans[i-1];
                }
            }
        }
        if(ans[n] == ans[0]){
            bool ok = false;
            if(s[0] == 'o'){
                if(ans[n-1] == 'S') ok = true;
            }
            else{
                if(ans[n-1] == 'W') ok = true;
            }
            if(ok){
                ans.pop_back();
                cout << ans << endl;
                return 0;
            }
        }
    }
    ans = "SW";
    {
        for(int i = 1; i < n; ++i){
            if(ans[i] == 'S'){
                if(s[i] == 'o'){
                    ans += ans[i-1];
                }
                else{
                    if(ans[i-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
            }
            else{
                if(s[i] == 'o'){
                    if(ans[i-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
                else{
                    ans += ans[i-1];
                }
            }
        }
        if(ans[n] == ans[0]){
            bool ok = false;
            if(s[0] == 'o'){
                if(ans[n-1] == 'W') ok = true;
            }
            else{
                if(ans[n-1] == 'S') ok = true;
            }
            if(ok){
                ans.pop_back();
                cout << ans << endl;
                return 0;
            }
        }
    }
    ans = "WS";
    {
        for(int i = 1; i < n; ++i){
            if(ans[i] == 'S'){
                if(s[i] == 'o'){
                    ans += ans[i-1];
                }
                else{
                    if(ans[i-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
            }
            else{
                if(s[i] == 'o'){
                    if(ans[i-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
                else{
                    ans += ans[i-1];
                }
            }
        }
        if(ans[n] == ans[0]){
            bool ok = false;
            if(s[0] == 'o'){
                if(ans[n-1] == 'W') ok = true;
            }
            else{
                if(ans[n-1] == 'S') ok = true;
            }
            if(ok){
                ans.pop_back();
                cout << ans << endl;
                return 0;
            }
        }
    }
    ans = "WW";
    {
        for(int i = 1; i < n; ++i){
            if(ans[i] == 'S'){
                if(s[i] == 'o'){
                    ans += ans[i-1];
                }
                else{
                    if(ans[i-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
            }
            else{
                if(s[i] == 'o'){
                    if(ans[i-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
                else{
                    ans += ans[i-1];
                }
            }
        }
        if(ans[n] == ans[0]){
            bool ok = false;
            if(s[0] == 'o'){
                if(ans[n-1] == 'S') ok = true;
            }
            else{
                if(ans[n-1] == 'W') ok = true;
            }
            if(ok){
                ans.pop_back();
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
