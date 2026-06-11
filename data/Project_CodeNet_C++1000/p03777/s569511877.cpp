#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a,b;
    cin >> a >> b;

    if(a=='H') cout << b;
    else if(b=='D') cout << 'H';
    else cout << 'D';

    cout << endl;
    return 0;
}