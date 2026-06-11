#include<iostream>
#include<algorithm>

using namespace std;

pair<int,int> A[100005];
long long Fr[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>A[i].first;
        A[i].second=i;
    }

    sort(A+1,A+n+1);

    int ind=n+1;
    for(int i=n; i>=1; i--)
    {
        ind=min(ind,A[i].second);
        Fr[ind]=Fr[ind]+1LL*(n-i+1)*(A[i].first-A[i-1].first);
    }

    for(int i=1; i<=n; i++)
        cout<<Fr[i]<<"\n";
    return 0;
}
