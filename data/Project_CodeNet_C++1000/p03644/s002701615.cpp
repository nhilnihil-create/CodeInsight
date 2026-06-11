#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[110];
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }

    int ans = 1;
    int num = 0;

    for (int i = 1; i <= N; i++) {
        bool can = true;
        int count = 0;
        int x = i;
        while (can) {
            if (x % 2) {
                can = false;
                break;
            }
            x /= 2;
            count++;
        }
        if (count > num) {
            ans = i;
        }
        num = max(num, count);
    }

    cout << ans << endl;
}