#include<bits/stdc++.h>
using namespace std;
int cnt[1000];
int main()
{
    int n,i,j,k,a;
    cin >> n;
    int amax = 0;
    for(i=0;i<n;i++)
    {
        cin >> a;
        cnt[a]++;
        amax = max(amax,a);
    }
    int mid ;
    if(amax%2==0)
    {
        mid=amax/2;
        if(cnt[mid]!=1)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    else
    {
        mid = (amax+1)/2;
        if(cnt[mid]!=2)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    int m = cnt[mid];
    for(i=amax;i>mid;i--)
    {
        if(cnt[i]<2)
        {
            cout << "Impossible" << endl;
            return 0;
        }
        m += cnt[i];
    }
    if(m==n)
    {
        cout << "Possible" << endl;

    }
    else cout << "Impossible" << endl;

}
