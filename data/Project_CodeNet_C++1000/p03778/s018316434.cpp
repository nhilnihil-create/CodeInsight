/**
 * @author: shashankchdhry
 * @made:   2020-04-05 12:14:49 
**/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int w, a, b;
    cin >> w >> a >> b;

    ll ans = abs(b-a)-w;
    cout << (ans>0?ans:0) << "\n";

    return 0;
}