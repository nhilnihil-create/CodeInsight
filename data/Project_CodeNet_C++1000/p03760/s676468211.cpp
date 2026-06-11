#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    string o, e;
    cin>>o>>e;
    int a, b;
    a = o.size();
    b = e.size();
    int n = a+b;
    int i, j, k;
    j = 0;
    k = 0;
    for( i = 1; i<=n; i++)
    {
        if(i%2 == 0)
        {
            cout<<e[j];
            j++;
        }
        else
        {
            cout<<o[k];
            k++;
        }
    }
    return 0;
}

