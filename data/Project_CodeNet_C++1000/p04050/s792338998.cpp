#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int N;
    cin >> N;
    int M;
    cin >> M;
    int A[105];
    for(int i = 1; i <= M; i++) {
        cin >> A[i];
    }
    if(M == 1) {
        if(A[1] % 2 == 0) {
            vector<int> ans;
            ans.push_back(2);
            if(A[1] > 2) ans.push_back(A[1] - 2);
            cout << A[1] << endl;
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i] << endl;
            }
            return 0;
        }
        vector<int> ans;
        ans.push_back(1);
        if(A[1] > 1) ans.push_back(A[1] - 1);
        cout << A[1] << endl;
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
        return 0;
    }
    if(A[M] % 2 == 1) swap(A[1], A[M]);
    for(int i = 2; i < M; i++) {
        if(A[i] % 2 == 1) {
            if(A[1] % 2 == 0) {
                swap(A[i], A[1]);
                continue;
            }
            if(A[M] % 2 == 0) {
                swap(A[i], A[M]);
                continue;
            }
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for(int i = 1; i <= M; i++) {
        cout << A[i];
        if(i < M) cout << " ";
    }
    cout << endl;
    if((A[1] % 2 == 1) && A[M] % 2  == 1) {
        if(A[1] == 1) {
            cout << M - 1 << endl;
            for(int i = 2; i < M; i++) {
                cout << A[i] << endl;
            }
            cout << A[M] + 1 << endl;
            return 0;
        }
        cout << M << endl;
        cout << A[1] - 1 << endl;
        for(int i = 2; i < M; i++) {
            cout << A[i] << endl;
        }
        cout << A[M] + 1 << endl;
        return 0;
    }
    if(A[1] % 2 == 1) {
        cout << M << endl;
        cout << A[1] + 1 << endl;
        for(int i = 2; i < M; i++) {
            cout << A[i] << endl;
        }
        cout << A[M] - 1 << endl;
        return 0;
    }
    cout << M + 1 << endl;
    cout << 1 << endl;
    for(int i = 1; i < M; i++) {
        cout << A[i] << endl;
    }
    cout << A[M] - 1 << endl;
    return 0;
}
