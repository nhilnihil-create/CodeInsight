#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    ll a , b , c; cin >> a >> b >> c;
    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << min (a * b , min(a * c , b * c)) <<endl;
    return 0;
}
