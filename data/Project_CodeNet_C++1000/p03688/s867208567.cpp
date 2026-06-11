#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int main(void){
    int N; cin >> N;
    A.resize(N);
    int minA = 10000000;
    int maxA = -1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        minA = min(minA, A[i]);
        maxA = max(maxA, A[i]);
    }
    
    if (maxA - minA > 1) {
        cout << "No" << endl;
        return 0;
    } else if (maxA - minA == 1) {
        int color = maxA;
        int not_unique_hat = 0;
        int unique_hat = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] != maxA) {
                unique_hat++;
            } else {
                not_unique_hat++;
            }
        }
        if (color <= unique_hat) {
            cout << "No" << endl;
            return 0;
        }
        
        if (!(unique_hat + 1 <= color && color <= unique_hat + not_unique_hat/2)) {
            cout << "No" << endl;
            return 0;
        }
    } else if (maxA - minA == 0) {
        int color_if_all_hats_are_unique = maxA + 1;
        int color_if_all_hats_are_not_unique_lower = 1;
        int color_if_all_hats_are_not_unique_upper = N/2;
        if (N != color_if_all_hats_are_unique && !(color_if_all_hats_are_not_unique_lower <= maxA && maxA <= color_if_all_hats_are_not_unique_upper)) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}
