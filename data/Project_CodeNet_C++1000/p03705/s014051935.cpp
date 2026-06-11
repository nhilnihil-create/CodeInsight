#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long N, A, B;
    cin >> N >> A >> B;
    long long ans = 0;
    if (A > B)
    {
        ans = 0;
    }else if (A == B)
    {
        ans = 1;
    }else if(A < B)
    {
        if (1 == N)
        {
            ans = 0;
        }else if (2 == N)
        {
            ans = 1;
        }
        else
        {
            ans = (B - A) * (N - 2) + 1;
        }
        
    }
    
    cout << ans << endl;
    
    return 0;
}