#include <bits/stdc++.h>
using namespace std;

int main(){
    string S[100];
    int N, L;
    int i;
    string tmp;

    cin >> N >> L;
    for (i=0; i<N; i++) {
        cin >> S[i];
    }

    sort(S, S+N);

    tmp = S[0];

    for (i=1; i<N; i++) {
        tmp = tmp + S[i];
    }

    cout << tmp << endl;

}