#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,C,K;
    cin >> N >> C >> K;
    vector<int>T(N);
    for (int i = 0; i < N; i++) {
        cin >> T.at(i);
    }
    sort(T.begin(), T.end());

    int count = 0;
    int icount = 0;

    if (C == 1){
        cout << N << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (i == N-1){
            count++;
        }
        for (int j = 1; j < min(C,N-i); j++) {
            if (T.at(i) + K >= T.at(i+j)){
                icount++;
                if (j == min(C,N-i)-1){
                    count++;
                    i += icount;
                    icount = 0;
                }
            }
            else {
                count++;
                i += icount;
                icount = 0;
                break;
            }
        }
    }
    cout << count << endl;
}

        


