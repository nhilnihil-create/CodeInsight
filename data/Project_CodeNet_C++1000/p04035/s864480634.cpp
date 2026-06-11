#include <bits/stdc++.h>
using namespace std;

int main()
{
        int N, L;
        int A[100005];

        cin >> N >> L;

        int pos = -1;
        for ( int i = 0; i < N; i++ ) {
                cin >> A[i];
                if ( i > 0 && A[i] + A[i - 1] >= L ) pos = i - 1;
        }

        if ( pos == -1 ) {
                cout << "Impossible" << '\n';
        } else {
                cout << "Possible" << '\n';
                for ( int i = 0; i < pos; i++ ) {
                        cout << i + 1 << '\n';
                }
                for ( int i = N - 2; i > pos; i-- ) {
                        cout << i + 1 << '\n';
                }
                cout << pos + 1 << '\n';
        }
        
        return ( 0 );
}