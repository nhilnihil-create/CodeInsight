#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <map> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

int main(){
    string s;
    cin >> s;

    string sei = "CODEFESTIVAL2016";
    ll res = 0;
    REP(i,16)
    {
        if(s[i] != sei[i])++res;
    }

    cout << res << endl;
    return 0;    
}

