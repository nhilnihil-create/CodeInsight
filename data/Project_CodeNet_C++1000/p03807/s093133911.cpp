#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long int N;
    cin >> N;
 
    long int arr[N];
 
    long int o = 0;
    long int e = 0;
 
    for(long int n=0; n<N; n++)
    {
        cin >> arr[n];
 
        if(arr[n] % 2)
        {
            o++;
        }
    }
 
    if(o % 2)
    {
        cout << "NO";
    }
 
    else
    {
        cout << "YES";
    }
 
    return 0;
}