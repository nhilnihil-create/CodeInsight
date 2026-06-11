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
    int n;
    cin >> n;
    int ans=0, i=0;
    while(ans<=n){
        ++i;
        ans += i;

        if(ans == n)
            break;
    }
    cout << min(n, i);
}