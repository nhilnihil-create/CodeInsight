#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    int sum = 0;
    int aaa = 999;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S.at(i);
        sum += S[i];
        if (S[i] % 10 != 0) {
            aaa = min(aaa, S[i]);
        }
    }
    if (sum % 10 == 0) {
        if (aaa == 999) {
            cout << 0 << endl;
            return 0;
        }
        cout << sum - aaa << endl;
    }else{
        cout << sum << endl;
    }
}