#include <functional>
#include <iostream>
#include <limits>
#include <queue>

using namespace std;

int64_t a[300'000];
int64_t lScore[100'001];
int64_t rScore[100'001];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < 3 * N; i++)
    {
        cin >> a[i];
    }

    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> lQ;
    priority_queue<int64_t, vector<int64_t>, less<int64_t>> rQ;
    int64_t lSum = 0;
    int64_t rSum = 0;

    for (int i = 0; i < N; i++)
    {
        lQ.push(a[i]);
        rQ.push(a[i + 2 * N]);

        lSum += a[i];
        rSum += a[i + 2 * N];
    }

    for (int i = 0; i <= N; i++)
    {
        if (i != 0)
        {
            lSum += a[i - 1 + N];
            lQ.push(a[i - 1 + N]);
            lSum -= lQ.top();
            lQ.pop();

            rSum += a[2 * N - i];
            rQ.push(a[2 * N - i]);
            rSum -= rQ.top();
            rQ.pop();
        }
        lScore[i] = lSum;
        rScore[N - i] = rSum;
    }

    int64_t mScore = numeric_limits<int64_t>::min();
    for (int i = 0; i <= N; i++)
    {
        mScore = max(mScore, lScore[i] - rScore[i]);
    }

    cout << mScore << endl;

    return 0;
}