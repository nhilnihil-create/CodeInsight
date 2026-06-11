#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n ; cin>> n;
    int start ; cin>> start ;
    vector<int> arr(n);
    for(int&p:arr) cin >> p;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        int first = abs(0-arr[i]) , second = abs(start - arr[i]);
        int mini = min (first , second);
        ans += (mini)*2;
    }
    cout << ans ;
    return 0 ;
}