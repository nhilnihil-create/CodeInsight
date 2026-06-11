#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,w;
    cin >> w >> a >> b;

    if(a+w < b) cout << b-(a+w);
    else if(b+w < a) cout << a-(b+w);
    else cout << 0;

    cout << endl;
    return 0;
}