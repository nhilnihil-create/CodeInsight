#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int j;
        j = A[i] - 1;
        if (A[j] - 1 == i) {ans++;}
    }
    cout << ans/2 << endl;



    return 0;
}
