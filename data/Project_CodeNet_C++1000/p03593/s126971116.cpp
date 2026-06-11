#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    map<char,int> m;
    rep(i,h) {
        string s;
        cin >> s;
        rep(j,w) {
            m[s[j]];
            m[s[j]]++;
        }
    }
    int num4=0, num2=0, num1=0;
    if(h%2==0 && w%2 ==0) {
        num4 = w/2*h/2;
    } else if(w%2 == 0) {
        num4 = (w/2)*(h-1)/2;
        num2 = w/2;
    } else if(h%2 == 0) {
        num4 = (w-1)/2*h/2;
        num2 = h/2;
    } else {
        num4 = (w-1)/2*(h-1)/2;
        num2 = (h-1)/2 + (w-1)/2;
        num1 = 1;
    }
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        int n = (*itr).second;
        num4 -= n/4;
        n%=4;
        num2 -= n/2;
        n%=2;
        if(num4 < 0) {
            num2 -= -num4*2;
            num4 = 0;
        }
        num1 -= n;
        if(num1 < 0 || num2 < 0 || num4 < 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
