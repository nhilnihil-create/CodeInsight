#include <bits/stdc++.h>
using namespace std;

int main()
{

        int N;
        cin >> N;
        long long A[N];
        int o_cnt = 0;
        int e_cnt = 0;
        for (int i = 0; i < N; ++i) {
                cin >> A[i];
                if (A[i] % 2 == 0) {
                        e_cnt++;
                }
                else {
                        o_cnt++;
                }
        }

        if (o_cnt % 2 != 0) {
                cout << "NO" << endl;
                exit(0);
        }
        int amari = o_cnt % 2;
        e_cnt += (o_cnt / 2 + amari);
        if (e_cnt == 1) {
                cout << "YES" << endl;
                exit(0);
        }
        int ans = e_cnt / 2;
        amari = e_cnt % 2;
        ans += amari;
                        cout << "YES" << endl;


}
