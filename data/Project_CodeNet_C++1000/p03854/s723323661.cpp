#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")




int main() {


    string s; cin >> s;
    ll n = s.length();

    while(s.length() > 0){
        if(s[n-1] == 'e'){
            if(n >= 5 && s.substr(n-5,n) == "erase"){
                s = s.substr(0,n-5);
                n = s.length();
            }else{
                cout << "NO";
                return 0;
            }
        }else if(s[n-1] == 'm'){
            if(n >= 5 && s.substr(n-5,n) == "dream"){
                s = s.substr(0,n-5);
                n = s.length();
            }else{
                cout << "NO";
                return 0;
            }
        }else if(s[n-1] == 'r'){
            if(n >= 7 && s.substr(n-7,n) == "dreamer"){
                s = s.substr(0,n-7);
                n = s.length();
            }else if(n >= 6 && s.substr(n-6,n) == "eraser"){
                s = s.substr(0,n-6);
                n = s.length();
            }else{
                cout << "NO";
                return 0;
            }
        }else{
            cout << "NO";
            return 0;
        }
    }


    cout << "YES";
    return 0;
}
