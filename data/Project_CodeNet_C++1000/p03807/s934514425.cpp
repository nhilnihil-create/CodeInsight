#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,count=0;
    cin >> n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(i=0; i<n; i++)
    {
        if(arr[i]%2!=0)
        {
           count++;
        }
    }
   if(count%2==0)
    cout << "YES";
   else
   cout << "NO";
    return 0;

}
