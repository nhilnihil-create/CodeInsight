#include <bits/stdc++.h>

using namespace std;

int main (void) {
    string S;
    cin >> S;

    bool can = true;
    int s_len = S.size();
    string t_rev;
    for ( int i = s_len-1; i >=0; i-- ) {
        t_rev += S.at(i);
        if ( t_rev.size() > 7 ) {
            can = false;
            break;
        }
        if ( t_rev == "maerd" || t_rev == "esare" ||
             t_rev == "remaerd" || t_rev == "resare" ) {
            t_rev = "";
        }
    }

    if ( can ) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
