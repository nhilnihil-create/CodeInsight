#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int max = 0;
    int ans = 1;
    for (int i = 1; i <= N; i++)
    {
        int a = i;
        int count = 0;
        while (a % 2 == 0)
        {
            a /= 2;
            count++;
        }
        if(max < count) {
            max = count;
            ans = i;
        }
    }
    cout << ans << endl;
}