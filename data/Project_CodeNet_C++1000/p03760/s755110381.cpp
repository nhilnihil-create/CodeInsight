#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    string O, E;
    cin >> O >> E;
    int maxv = max((int)O.size(), (int)E.size());

    rep(i, maxv){
        // cout << O[i] << E[i];
        if(O.size()!=0){
            cout << O[0];
            O.erase(0, 1);
            // cout << O << endl;
        }
        if(E.size()!=0){
            cout << E[0];
            E.erase(0, 1);
            // cout << E << endl;
        }
    }
    cout << endl;

    return 0;
}