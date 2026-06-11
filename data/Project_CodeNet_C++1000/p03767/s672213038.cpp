#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
    int n,i;
    cin >> n;
    long long int sum=0,arr[3*n];
    for(i=0; i<3*n; i++)
    {
       cin >> arr[i];
    }
     sort(arr, arr+(3*n), greater<int>());
     for(i=1; i<2*n; i+=2)
    {
        sum+=arr[i];
    }
    cout << sum;
    return 0;

}
