#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int main(void)
{
    int N;
    int p[MAX_N];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (p[i] == i) {
            answer++;
            i += 1;
        }
    }
    cout << answer << endl;
    return 0;
}
