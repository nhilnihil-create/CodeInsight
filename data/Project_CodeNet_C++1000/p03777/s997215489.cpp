#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    char ans = 'D';
    char a, b;
    cin >> a >> b;
    if((a=='H'&&b=='H')||(a=='D'&&b=='D')){
        ans = 'H';
    }
cout << ans << "\n";
    return 0;
}
