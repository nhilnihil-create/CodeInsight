#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,mi=INT_MAX,cost=0;
    cin>>n;
    int ara[n],j;
    for(i=0;i<n;i++){
        cin>>ara[i];
    }
    for(i=-100;i<=100;i++){
        cost=0;
        for(j=0;j<n;j++){
            cost+=(ara[j]-i)*(ara[j]-i);
        }
        mi=min(cost,mi);
    }
    cout<<mi<<endl;
    return 0;
}