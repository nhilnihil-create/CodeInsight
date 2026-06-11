#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

int main()
{
    lint n;cin >> n;
    vector<int> v1, v2;
    REP(i,n){
        int a;
        cin >> a;
        if(i%2==0){
            v1.emplace_back(a);
        }else{
            v2.emplace_back(a);
        }
    }
    if(n%2==0){
        IREP(i,SZ(v2)){
            cout << v2[i] << " ";
        }
        REP(i, SZ(v1))
        {
            cout << v1[i] << " ";
        }
    }else{
        IREP(i, SZ(v1))
        {
            cout << v1[i] << " ";
        }
        REP(i, SZ(v2))
        {
            cout << v2[i] << " ";
        }
    }
    return 0;
}