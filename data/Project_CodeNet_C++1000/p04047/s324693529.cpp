#include<iostream>
#include<algorithm>
#include<string>
#include<bits/stdc++.h>
using std::string;
int main()
{
    int N;
    std::cin >> N;
    int arr[2 * N];
    for(int i = 0; i < 2 * N; i++)
    {
        std::cin >> arr[i];
    } 
    int n = sizeof(arr)/sizeof(arr[0]);
    std::sort(arr, arr + n);
    int ans = 0;
    for(int i = 0; i < 2 * N; i++)
    {
        if(i % 2 == 0)
        {
            ans += arr[i];
        }
    }
    std::cout << ans << '\n';
}