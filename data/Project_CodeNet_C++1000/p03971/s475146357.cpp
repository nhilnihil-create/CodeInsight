#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    int N, A, B;
    string S;
    cin >> N >> A >> B >> S;
    vector<string> x(N,"No");
    int a = 0; //予選通過人数全員のカウント
    int b = 0; // 予選通過外国人学生のカウント

    for(int i = 0; i < N; i++) {
        if(S[i] == 'a' && a < (A + B)) {
            x[i] = "Yes";
            a++;
        }
        else if(S[i] == 'b' && a < (A + B) && b < B) {
            x[i] = "Yes";
            a++;
            b++;
        }
    }
    for(int i = 0; i < N; i++) {
        cout << x[i] << endl;
    }
    return 0;
}