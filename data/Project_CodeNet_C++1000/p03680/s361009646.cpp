#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;  cin >> n ;
    vector<int> arr(n);
    for(int&p:arr) cin >> p;
    int ans = 0 ;
    int i = 0 ;
    while(i<n)   
    {
        if(ans > 1000000)
        {
            cout << -1 << endl;
            return 0;
        }
        if(arr[i]==2)
        {
            cout << ans+1 << endl;
            return 0 ;
        }
        if(arr[i]!=2)
        {
            i = arr[i]-1;
            ans ++ ;
        }
    }
    return 0 ;
}