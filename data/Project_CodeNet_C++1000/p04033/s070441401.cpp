#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int a, b;
    cin >> a >> b;
    if(a > 0) cout << "Positive" << endl;
    else if(b >= 0) cout << "Zero" << endl;
    else if((b-a) % 2 == 0) cout << "Negative" << endl;
    else cout << "Positive" << endl;
}
