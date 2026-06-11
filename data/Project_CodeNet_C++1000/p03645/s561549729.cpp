#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    int a, b;
    vector<bool> ftoi;
    vector<bool> itoN;
    ftoi.resize(N);
    fill(ftoi.begin(), ftoi.end(), false);
    itoN.resize(N);
    fill(itoN.begin(), itoN.end(),false);
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;

        if (a > b) swap(a, b);

        if (a == 1)
        {
            ftoi[b - 1] = true;
        }
        if (b == N)
        {
            itoN[a - 1] = true;
        }
        
    }

    for (int i = 0; i < N; i++)
    {
        if (ftoi[i] & itoN[i])
        {
            cout << "POSSIBLE" << endl;
            return 0;
        }
        
    }
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}