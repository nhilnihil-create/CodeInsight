#include <bits/stdc++.h>

using namespace std;

int main (void) {
    string s;
    cin >> s;
    int s_len = s.size();

    deque<char> dq;
    for ( int i = 0; i < s_len; i++ ) {
        if ( s.at(i) != 'B' )
            dq.push_back(s.at(i));
        else if ( !dq.empty() )
            dq.pop_back();
    }

    while ( !dq.empty() ) {
        cout << dq.front();
        dq.pop_front();
    }
    cout << endl;
    return 0;
}

