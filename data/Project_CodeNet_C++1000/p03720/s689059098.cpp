#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    cin>>n>>m;

    int* city = new int [n+1]();
    for(int i=0;i<m;i++)
    {
        int a ,b;
        cin>>a>>b;
        city[a]++;
        city[b]++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<city[i]<<"\n";
    }
}