#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, x;
    cin >> N >> x;
    if (x == 1 || x == 2*N-1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (N == 2) {
        cout << "1\n2\n3" << endl;
        return 0;
    }
    if (x > 2) {
        int now = 3;
        for (int i = 1; i <= N-2; i++) {
            while (now == 2 || now == x || now == 2*N-1) now++;
            cout << now << endl;
            now++;
        }
        cout << 1 << endl << x << endl << 2*N-1 << endl << 2 << endl;
        for (int i = N+3; i <= 2*N-1; i++) {
            while (now == 2 || now == x || now == 2*N-1) now++;
            cout << now << endl;
            now++;
        }
    }else if (x == 2) {
        int now = 3;
        for (int i = 1; i <= N-2; i++) {
            while (now == 2 || now == 2*N-2 || now == 2*N-1) now++;
            cout << now << endl;
            now++;
        }
        cout << 2*N-1 << endl << 2 << endl << 1 << endl << 2*N-2 << endl;
        for (int i = N+3; i <= 2*N-1; i++) {
            while (now == 2 || now == 2*N-2 || now == 2*N-1) now++;
            cout << now << endl;
            now++;
        }
    }
    return 0;
}