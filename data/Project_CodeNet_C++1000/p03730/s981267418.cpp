#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,C;
    cin >> A >> B >> C;
    long long i=A;
    bool isYes = false;

    while(i <= A*B)
    {
        if(i%B==C)
        {
            isYes = true;
            break;
        }
        i += A;
    }
    
    if(isYes) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}