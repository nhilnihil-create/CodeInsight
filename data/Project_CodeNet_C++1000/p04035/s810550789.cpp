#include <bits/stdc++.h>

using namespace std;

int a[100100];

int main()
{
    int n,l,i,k = 0;
    cin >> n >> l;
    for(i = 0; i < n; i ++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 0; i < n-1; i ++)
    {
        if(a[i] + a[i+1] > a[k] + a[k+1]) k = i;
    }
    if(a[k] + a[k+1] < l) cout << "Impossible" << endl;
    else
    {
        cout << "Possible" << endl;
        k ++;
        for(i = n-2; i >= k; i --) printf("%d\n",i+1);
        for(i = 0; i < k; i ++) printf("%d\n",i+1);
    }
    return 0;
}