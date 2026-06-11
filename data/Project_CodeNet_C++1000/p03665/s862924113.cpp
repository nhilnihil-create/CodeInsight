#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long factorial(int a)
{
    if (a)
    {
        return 1;
    }else
    {
        return factorial(a - 1);
    }
    
}

int main(int argc, char const *argv[])
{
    int N, P;
    cin >> N >> P;
    vector<int> A;
    A.resize(N);
    int cntodd = 0, cnteven = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        (A[i] % 2 ? cntodd++ : cnteven++);
    }

    long long ans;
    if (cnteven == N)
    {
        if (P)
        {
            ans = 0;
        }else
        {
            ans = (long long)pow(2.0, N);
        }
        
    }else
    {
        ans = (long long)pow(2.0, N - 1);
    }

    cout << ans << endl;
    
    return 0;
}