#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()

const string YES = "Yes";
const string NO = "No";

int main(){
    string s;
    cin >> s;
    if(s.substr(0, 4) == "YAKI"){
        cout << YES << endl;
    }else{
        cout << NO << endl;
    }
    return 0;
}
