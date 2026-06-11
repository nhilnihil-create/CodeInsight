#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int64_t k;
    cin >> k;
    int n = S.size();
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        A[i] = S[i] - 'a';
    int m = 26;
    for (auto &a: A){
        if (a == 0)
            continue;
        if (m - a <= k){
            k -= m - a;
            a = 0;
        }
    }
    A[n - 1] += k;
    A[n - 1] %= m;
    for (const auto &a: A)
        cout << char('a' + a);
    cout << endl;
}