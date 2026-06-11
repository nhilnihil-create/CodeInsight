#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int r = a%b;
    string ans = "NO";
    rep(i, b){
        if ((r*i)%b == c) ans = "YES";
    }
    cout << ans << endl;

}