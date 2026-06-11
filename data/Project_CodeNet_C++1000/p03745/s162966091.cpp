#include <iostream>
#include <vector>
using namespace std;

bool upDown(int a, int b)
{
    return a < b;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> A;
    int in;
    for (int i = 0; i < N; i++)
    {
        cin >> in;
        A.emplace_back(in);
    }

    vector<bool> up;
    for (int i = 1; i < N; i++)
    {
        if (A[i - 1] == A[i]) continue;
        up.emplace_back(upDown(A[i - 1], A[i]));
    }
    
    int cnt = 1;
    for (int i = 1; i < up.size(); i++)
    {
        if (up[i - 1] != up[i])
        {
            cnt++;
            i++;
        }

    }
    
    cout << cnt << endl;
    
    return 0;
}