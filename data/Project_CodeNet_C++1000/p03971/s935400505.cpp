#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,A,B;
    string S;
    cin >> N >> A >> B >> S;
    int cnt = 1;
    int res = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'a') {
            if(res < A+B) {
                res++;
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else if(S[i] == 'c') {
            cout << "No" << endl;
        }
        else {
            if(res < A+B && cnt <= B) {
                cnt++;
                res++;
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}
