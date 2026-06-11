#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string s;
    cin >> s;

    int start, end;
    rep(i, s.size()) if (s[i] == 'A') {
        start = i;
        break;
    }
    rep(i, s.size()) if (s[s.size() - i - 1] == 'Z') {
        end = s.size() - i - 1;
        break;
    }

    put(end - start + 1);
    
    return 0;
}