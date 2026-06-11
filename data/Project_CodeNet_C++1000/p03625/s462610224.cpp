#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    map<int, int> A;
    int a;
    for ( int i=0; i<N; i++ ) {
        cin >> a;
        A[a]++;
    }

    /* 同じ長さが2本以上ずつある棒の中から
     * 長い方から２つ探す */
    int longest1 = 0, longest2 = 0;
    for ( auto itr : A ) {
        if ( itr.second >= 2  && itr.first > longest2 ) {
            if ( itr.first > longest1 ) {
                longest2 = longest1;
                longest1 = itr.first;
            }
            else {
                longest2 = itr.first;
            }
        }
    }

    long long ans;
    if ( A[longest1] >= 4 )
        ans = (long long)longest1 * longest1;
    else
        ans = (long long)longest1 * longest2;

    cout << ans << endl;

    return 0;
}
