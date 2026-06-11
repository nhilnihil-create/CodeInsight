#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    int state = 0;
    int ans = 1;
    for (int i = 1; i < N; ++i)
    {
        switch (state)
        {
        case 1:
            if (A[i] < A[i - 1])
            {
                state = 0;
                ++ans;
                break;
            }
        case 0:
            if (A[i] > A[i - 1])
            {
                state = 1;
            }
            else if (A[i] < A[i - 1])
            {
                state = -1;
            }
            break;
        case -1:
            if (A[i] > A[i - 1])
            {
                state = 0;
                ++ans;
                break;
            }
        }
    }
    cout << ans << endl;
}