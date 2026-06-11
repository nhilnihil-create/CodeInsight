#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    int maxa=0;
    int maxb=0;
    for(int i=0;i<n;i++)
    {
        int a,b;cin>>a>>b;

        if(maxa<a)
        {
            maxa=a;
            maxb=b;
        }
    }

    cout<<maxa+maxb<<"\n";

    return 0;
}
