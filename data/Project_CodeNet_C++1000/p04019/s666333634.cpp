#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    string S; cin >> S;
    int n = 0, w = 0, e = 0, s = 0;
    for(int i = 0; i < (int)S.size(); i++){
        if(S[i] == 'N') n++;
        if(S[i] == 'S') s++;
        if(S[i] == 'E') e++;
        if(S[i] == 'W') w++;
    }

    if((0 < n && s == 0) || (n == 0 && 0 < s)){
        cout << "No" << endl;
        return 0;
    }
    if((0 < e && w == 0) || (e == 0 && 0 < w)){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}
