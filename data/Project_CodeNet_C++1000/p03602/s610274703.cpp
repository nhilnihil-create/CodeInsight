#include <bits/stdc++.h>
using namespace std;
long long  A[1000][1000];
int main()
{
    int N;
    cin>>N;
    long long  ans=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>A[i][j];
    for(int i=0;i<N;i++)
      for(int j=0;j<=i;j++){
        int biaozhi=1;
        for(int k=0;k<N;k++)
            if(A[i][j]>A[i][k]+A[k][j]){
                cout<<-1;
                return 0;
            }
            else if(i!=k&&j!=k&&A[i][j]==A[i][k]+A[k][j])
                biaozhi=0;
        if(biaozhi)
            ans+=A[i][j];
      }
    cout<<ans;
    return 0;
}