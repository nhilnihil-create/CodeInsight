#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A, B;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
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