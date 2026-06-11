#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, st;
    cin>>n>>st;
    int t[n];
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
    }
    int s=0;
    for(auto i=1;i<n;i++)
    {
        if(t[i]-t[i-1] < st)
        {
            s+=t[i]-t[i-1];
        }
        else
            s+=st;
    }
    s+=st;
    cout<<s;
    
    return 0;
}