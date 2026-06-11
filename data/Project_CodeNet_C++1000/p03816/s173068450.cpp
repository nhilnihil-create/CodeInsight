#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100005],ans;
int main()
{
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort ( a + 1 , a + 1 + n);
    for (int i = 1;i <= n;i++){
        if(a[i]==a[i-1]) ans++;
    }
    if(ans&1) ans++;
    cout << n-ans << endl;
    return 0;
}