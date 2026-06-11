#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <bitset>
#include <cmath>
#include <string>
#include <stdlib.h>

#define ll long long
#define repp(i,a,b) for(int i=(int)a;i<(int)b;++i)

using namespace std;

int N;
vector<bool> S(100010);

bool solve(bool f, bool s) {
    vector<bool> zoo(N); zoo[0] = f; zoo[1] = s;
    repp(i,1,N-1) {
        if (S[i] == zoo[i]) zoo[i+1] = zoo[i-1];
        else zoo[i+1] = !zoo[i-1];
    }

    if ( ((S[0] == zoo[0]) == (zoo[N-1] == zoo[1])) && ((S[N-1] == zoo[N-1]) == (zoo[0] == zoo[N-2])) ) {
        repp(i,0,N) {
            if (zoo[i]) cout << 'S';
            else cout << 'W';
        }
        cout << endl;
        return true;
    }
    return false;
}

int main() {
    cin >> N;
    string s; cin >> s;
    repp(i,0,N) S[i] = s[i] == 'o';

    bool can = false;
    can |= solve(1,1);
    if (can) return 0;
    can |= solve(1,0);
    if (can) return 0;
    can |= solve(0,0);
    if (can) return 0;
    can |= solve(0,1);
    if (can) return 0;
    cout << -1 << endl;
}
