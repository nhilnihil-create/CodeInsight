#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int x=0 , y;
    int n ;
    cin >> n;
    int arr[n+1];
    arr[0]=-1;
    for(int i =1 ; i <=n ; i++)
    {
        cin >> arr[i];
        if(arr[i]==i&&arr[i-1]!=i-1)
        {
            x++;
        }
        else if(arr[i]==i&&arr[i-1]==i-1)
        {
            arr[i]--;
        }
    }
    cout << x ;
    return 0;
}
