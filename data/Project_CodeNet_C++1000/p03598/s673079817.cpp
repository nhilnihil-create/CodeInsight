#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,x[101],i,dis=0;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>x[i];
    }
    for(i=1;i<=n;i++){
        if(x[i]<=(k/2)) dis+=(2*x[i]);
        else{
            dis+=(2*(k-x[i]));
        }
    }cout<<dis;
    return 0;
}
