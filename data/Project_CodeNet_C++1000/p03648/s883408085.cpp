#include<iostream>
#include<cstdio>
using namespace std;
long long k,a[50][51];
int main()
{
    ios::sync_with_stdio(false);
    cin>>k;
    for(int i=1;i<=50;++i)
        a[0][i]=49;
    for(int i=1;i<50;++i)
        for(int j=1;j<=50;++j)
        {
            if(i==j) a[i][j]=a[i-1][j]+50;
            else a[i][j]=a[i-1][j]-1;
        }
    long long w=k/50,g=k%50;
    cout<<50<<endl;
    for(int i=1;i<=50;++i)
        cout<<w+a[g][i]<<' ';
    cout<<endl;
    return 0;
}