#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    set<int> se;
    rep(i,3){
        int a;
        cin >> a;
        se.insert(a);
    }
    cout << se.size() << '\n';
    return 0;
}
