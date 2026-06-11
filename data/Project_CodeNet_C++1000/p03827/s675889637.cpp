#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    string S;

    cin >> N >> S;

    int maxcnt=0, cnt=0;
    for (int i=0; i<N; i++) {
        if (S[i]=='I') cnt++;
        else if (S[i]=='D') cnt--;

        maxcnt=max(maxcnt, cnt);
    }
    cout << maxcnt << endl;

    return 0;
}