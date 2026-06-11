#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main() {
    int x,a,b;
    cin >> x >> a >>b;

    if(abs(x-a)>abs(x-b)) cout << 'B' <<endl;
    else cout <<'A'<<endl;
}