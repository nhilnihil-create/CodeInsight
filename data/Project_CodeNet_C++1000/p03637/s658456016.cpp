#include <bits/stdc++.h>
using namespace std;

int main()
{

        int N;
        cin >> N;
        int a[N];
        int c1 = 0;
        int c2 = 0;
        int c4 = 0;
        for (int i = 0; i < N; ++i) {
                int tmp;
                cin >> tmp;
                if (tmp % 4 == 0) {
                        c4++;
                }
                else if (tmp % 2 == 0) {
                        c2++;
                }
                else {
                        c1++;
                }
        }

        if (c2 == 1) {
                c2 = 0;
                c1++;
        }

        if (c1 > 0 && c4 == 0) {
                cout << "No" << endl;
        }
        else if (c1 > c4+1) {
                cout << "No" << endl;
        }
        else if (c2 > 0 && c1 > c4) {
                cout << "No" << endl;
        }
        else {
                cout << "Yes" << endl;
        }

}
