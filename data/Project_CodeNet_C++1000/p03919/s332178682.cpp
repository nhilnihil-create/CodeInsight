#include <bits/stdc++.h>
#include <numeric>
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())

#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
#define LL long long
#define Dev 1000000007

// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    rep(i,h){
        rep(j,w){
            string temp;
            cin >> temp;
            if(temp=="snuke"){
                cout << (char)('A'+j) << (i + 1) << endl;
                return 0;
            }
        }
    }
    return 0;
}
