#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if(a[n-1]-a[0] >= 2) 
    {
        cout << "No" << endl;
    }
    else if(a[n-1]-a[0] == 1) 
    {
        int cnt0 = 0, cnt1 = 0;
        for(int i=0;i<n;i++) 
        {
            if(a[i]==a[0]) cnt0++;
            else cnt1++;
        }
        if(cnt0 <= a[0] && (a[0]-cnt0+1)*2 <= cnt1) 
        cout << "Yes" << endl;
        else 
        cout << "No" << endl;
    } 
    else if(a[n-1]-a[0] == 0) 
    {
        if(n == a[0]+1 || n >= a[0]*2) 
        cout << "Yes" << endl;
        else 
        cout << "No" << endl;
    }
}