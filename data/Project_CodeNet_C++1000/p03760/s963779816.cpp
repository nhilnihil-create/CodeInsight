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
    string a, b;
    cin >> a >> b;
    for(int i=0; i<max(a.size(), b.size()); ++i){
        if(i < (int)a.size())
            cout << a[i];
        if(i<(int)b.size())
            cout << b[i];
    }
    return 0;
}
