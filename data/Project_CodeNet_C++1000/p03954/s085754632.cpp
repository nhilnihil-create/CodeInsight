#include <bits/stdc++.h>

using namespace std;
int kt(vector<int> &a)
{
    int n = a.size();
    int mid = a.size()/2;
    {
        int a2 = a[mid], a1 = a[mid-1], a3 = a[mid+1];
        if(a1==a2||a2==a3)
            return a2;
    }
    int l = mid, r = mid;
    while(l>0)
    {
        if(a[l]==(1-a[l-1]))
        l--;
        else
        break;
    }
    while(r<(n-1))
    {
        if(a[r]==(1-a[r+1]))
        r++;
        else
        break;
    }
    int x = r-mid;
    int y = mid-l;
    if(x>y) return a[l];
    return a[r];
}
int main()
{
    //freopen("input","r",stdin);
    int n;
    cin >> n;
    vector<int> a(2*n-1);
    for(int i = 0;i<2*n-1;i++)
    cin >> a[i];
    int l = 1;
    int r = 2*n-1;
    int soll = -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        vector<int> b;
        for(int i = 0;i<2*n-1;i++)
        b.push_back((a[i]>=mid));
        int sol = kt(b);
        if(sol==0)
            r = mid-1;
        if(sol==1)
        {
            l = mid + 1;
            soll = mid;
        }
    }
    cout << soll;
    return 0;
}
