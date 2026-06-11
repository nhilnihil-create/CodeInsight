#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;

int n;
int a[MAXN];

int main()
{
        cin>>n;
        for(int i = 0;i<n*2;i++)cin>>a[i];
        int sol = 0;
        sort(a , a+n*2);
        for(int i = 0;i<n*2;i+=2)sol+=a[i];
        cout<<sol;
        return 0;
}
