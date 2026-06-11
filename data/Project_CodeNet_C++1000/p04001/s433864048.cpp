#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> s(N);
    rep(i, N) s[i] = (int)(S[i] - '0');
    long long int sum = 0;
    rep(i, 1<<(N-1)) {
        long long int sum1 = 0;
        long long int temp = s[0];
        rep(j, N-1) {
            int k = (i >> j) %2;
            if(k){
                sum1 += temp;
                temp = s[j+1]; 
            } else {
                temp = temp * 10 + s[j+1];
            }
        }
        sum1 += temp;
        sum += sum1;
    }
    cout << sum << endl;
}
