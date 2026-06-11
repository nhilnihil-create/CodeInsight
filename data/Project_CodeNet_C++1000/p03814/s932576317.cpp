#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.length();
    int ta=0, tb=n-1;
    for(int i=0; i<n; ++i){
        if(s[i]=='A'){
            ta = i;
            break;
        }
    }
    for(int i=n-1; i>=0; --i){
        if(s[i]=='Z'){
            tb = i;
            break;
        }
    }

    cout << tb-ta+1;
    return 0;
}
