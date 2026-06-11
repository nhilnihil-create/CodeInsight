#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int *A = new int[M];
    int *B = new int[M];
    for (int i = 0; i < M; ++i)
    {
        cin >> A[i] >> B[i];
    }
    int *ans = new int[N]{0};
    for (int i = 0; i < M; ++i)
    {
        ++ans[A[i] - 1];
        ++ans[B[i] - 1];
    }
    for (int i = 0; i < N; ++i)
    {
        cout << ans[i] << endl;
    }
}