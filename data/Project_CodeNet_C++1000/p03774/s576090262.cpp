#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(M);
    vector<int> D(M);

    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i) >> B.at(i);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> C.at(i) >> D.at(i);
    }

    int c;
    int d;
    int min;
    int l;

    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        min = 2147483647;
        for (int j = 0; j < M; j++)
        {
            l = abs(A.at(i) - C.at(j)) + abs(B.at(i) - D.at(j));
            if (l < min)
            {
                min = l;
                P.at(i) = j + 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << P.at(i) << endl;
    }

    return 0;
}