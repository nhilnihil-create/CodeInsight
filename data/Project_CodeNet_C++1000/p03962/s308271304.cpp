#include<iostream>
using namespace std;
int main()
{
    int i, ans = 0, X[101] = {0}, a[3];
    cin >> a[0] >> a[1] >> a[2];
    X[a[0]]++;
    X[a[1]]++;
    X[a[2]]++;
    for(i=0;i<101;i++)
    {
        if(X[i]!=0)
        ans++;
    }
    cout << ans;
    return 0;
}