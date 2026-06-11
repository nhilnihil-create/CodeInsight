#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,M,sum;
    cin >> N ;
    vector<int> T(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T.at(i);
        sum += T.at(i);
    }
    cin >> M ;
    vector<int> P(M),X(M);
    for (int i = 0; i < M; i++)
    {
        cin >> P.at(i) >> X.at(i);
        cout << (sum - T.at(P.at(i)-1) + X.at(i)) << endl;
    }
    return 0;
}