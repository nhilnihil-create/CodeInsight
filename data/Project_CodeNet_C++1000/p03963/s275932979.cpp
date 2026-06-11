#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long int A,B;
    cin >> A >> B;
    long long int ans=B;
    for(int i=0; i<A-1; i++)
    {
        ans*=(B-1);
    }
    cout << ans <<endl;
}
