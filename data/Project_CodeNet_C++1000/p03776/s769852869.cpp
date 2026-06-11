#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
using namespace std;
const int INF=(int)1e9+10;
const int MOD=(int)1e9+7;
map<long long,int> freq;
long long C[55][55],ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<=50;i++)
        C[i][0]=1,
        C[i][i]=1;
    for(int i=1;i<=50;i++)
        for(int j=1;j<i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    long double cnt=0;
    int n,a,b,num=0;
    cin>>n>>a>>b;
    vector<long long> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i],
        freq[v[i]]++;
    sort(v.rbegin(),v.rend());
    if(freq[v[0]]>=a)
    {
        cnt=v[0];
        for(int i=a;i<=min(b,freq[v[0]]);i++)
            ans+=C[freq[v[0]]][i];
    }
    else
    {
        for(int i=0;i<a;i++)
            cnt+=v[i];
        cnt/=a;
        for(int i=0;i<a;i++)
            if(v[i]==v[a-1])
                num++;
        ans=C[freq[v[a-1]]][num];
    }
    cout<<fixed<<setprecision(12)<<cnt<<"\n"<<setprecision(0)<<ans;
    return 0;
}
