

#include<bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);

int main()
{
    speed;

    int n;
    cin>>n;

    vector<int>v(n);
    int ans=INT_MAX;

    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=-100;i<=100;i++)
    {
        int cal=0;

        for(int j=0;j<n;j++)
        {
            cal+=((v[j]-i)*(v[j]-i));
        }

        ans=min(ans,cal);
    }

    cout<<ans<<"\n";
}