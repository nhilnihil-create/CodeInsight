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
    ll n;
    cin >> n;
    n *= 3;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    sort(all(a));


    ll s=0, t=2, i=0;
    while(i<n/3){
        s+=a[n-t];
        t +=2;
        ++i;
    }

    cout << s;
}