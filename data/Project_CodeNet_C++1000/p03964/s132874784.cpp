#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;

    cin >> N;

    long long int tn = 1, an = 1;
    for(int i = 0; i < N; ++i)
    {   
        int T, A;
        cin >> T >> A;
        long long int p = max(max(tn/T, an/A),(long long int)1);
        if(T*p >= tn && A*p >= an)
        {
            tn = T*p;
            an = A*p;
        }
        else
        {
            tn = T*(p+1);
            an = A*(p+1);            
        }
        
    }

    cout << (long long int)tn + (long long int)an << endl;

    return 0;
}

