#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    string state = "INIT";
    int cnt = 1;
    for (int i = 0; i < N - 1; i++)
    {
        // cout << i << " " << state << endl;
        if (A[i] < A[i + 1])
        {
            if (state == "INIT") {
                state = "UP";
                continue;
            }
            else if (state == "UP")
            {
                continue;
            }
            else if (state == "DOWN") {
                state = "INIT";
                cnt++;
            }
        }
        else if (A[i] > A[i+1]) {
            if (state == "INIT") {
                state = "DOWN";
                continue;
            }
            else if (state == "UP")
            {
                state = "INIT";
                cnt++;
            }
            else if (state == "DOWN")
            {
                continue;
            }
                            }
        else
        {
            continue;
        }
        }
    cout << cnt << endl;
}