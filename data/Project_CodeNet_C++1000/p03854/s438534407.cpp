#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<(n); i++)
#define REPS(i, n) for(int i=0; i<=(n); i++)
#define FOR(i, a, b) for(int i=a; i<(b); i++)
#define FORS(i, a, b) for(int i=a; i<=(b); i++)
// for container x
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

int main(){
    string s;
    cin >> s;

    reverse(ALL(s));
    
    int i=0;
    while (i < SIZE(s)){
        if (i + 5 <= SIZE(s) && s.substr(i, 5) == "maerd") i+=5;
        else if (i + 7 <= SIZE(s) && s.substr(i, 7) == "remaerd") i+=7;
        else if (i + 5 <= SIZE(s) && s.substr(i, 5) == "esare") i+=5;
        else if (i + 6 <= SIZE(s) && s.substr(i, 6) == "resare") i+=6;
        else break;
    }

    if (i == SIZE(s)) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return 0;
}