#include <bits/stdc++.h>
#define int long long
using namespace std;
//string sort (s.begin(),s.end());

main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	int a[n+10];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    int f=0;
    int idx;
    for(int i=0;i<n-1;i++)
    {

        if(a[i]+a[i+1]>=k)
        {
            f=1;
            idx=i+1;
            break;
        }

    }
    if(f==0)
    {
         cout<<"Impossible"<<endl;
    }
    else
    {
        cout<<"Possible"<<endl;
        for(int i=1;i<idx;i++)
        {
            cout<<i<<endl;
        }
        for(int i=n-1;i>=idx;i--)
        {
            cout<<i<<endl;
        }

    }



}


