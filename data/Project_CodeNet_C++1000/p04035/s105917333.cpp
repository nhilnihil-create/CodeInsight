#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,l;
    cin>>n>>l;
    int arr[n+1];
    ll sm=0;
    for(int i=1; i<=n; i++)cin>>arr[i],sm+=arr[i];

    if(sm<l)
    {
        cout<<"Impossible\n";
        return 0;
    }
    vector<int>ans;
    for(int i=1; i<n; i++)
    {
        if(arr[i]+arr[i+1]>=l)
        {
            if(i>1)
            {
                for(int j=1; j<i; j++)
                    ans.push_back(j);
            }
            if(i+1 < n)
            {
                for(int j=n-1; j>i; j--)
                    ans.push_back(j);
            }

            ans.push_back(i);

            cout<<"Possible\n";
            for(int j:ans)
                cout<<j<<endl;
            return 0;
        }
    }
    cout<<"Impossible\n";

}
