#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll n = s.size();
    ll ndx = 0;
    string dream = "maerd";
    string dreamer = "remaerd";
    string erase = "esare";
    string eraser = "resare";
    while (ndx < n){
        if (s[ndx]=='m'){
            rep1(i, 5){
                if (s[ndx+i]!=dream[i]){
                    cout << "NO" << endl;
                    return 0;
                }
            }
            ndx += 5;
        }
        else if (s[ndx]=='e'){
            rep1(i, 5){
                if (s[ndx+i]!=erase[i]){
                    cout << "NO" << endl;
                    return 0;
                }
            }
            ndx += 5;
        }
        else if (s[ndx]=='r'){
            if (s[ndx+2]=='m'){
                rep1(i, 7){
                    if (s[ndx+i]!=dreamer[i]){
                        cout << "NO" << endl;
                        return 0;
                    }
                }
                ndx += 7;
            }
            else if (s[ndx+2]=='s'){
                rep1(i, 6){
                    if (s[ndx+i]!=eraser[i]){
                        cout << "NO" << endl;
                        return 0;
                    }
                }
                ndx += 6;
            }
            else{
                cout << "NO" << endl;
                return 0;
            }
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    //printf("%.12f", ans);
}