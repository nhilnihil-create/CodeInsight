#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int  n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans =0;
    int curr =1;
    set<int> m;

    while( curr != 2)
    {

        if( m.find( curr) != m.end() )
        {
         cout<<-1;
         return 0;
        }
        m.insert(curr);
        curr = a[ curr ];
        ans++;
    }
    cout<<ans;
}