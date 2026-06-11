#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main() {
    int A,B,C;
    cin >> A >> B >> C;
    if (A == 5 || A == 7) {
        if (B == 5 || B == 7) {
            if (C == 5 || C == 7) {
                if (A+B+C==5+7+5) {
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;

                }

            } else {
                cout << "NO" << endl;

            }

        } else {
            cout << "NO" << endl;

        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}