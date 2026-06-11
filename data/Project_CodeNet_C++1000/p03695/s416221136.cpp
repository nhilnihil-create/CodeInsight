#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    vector<int >col(9,0);
    int nh = 0;
    vector<int >nos(n,0);
    for(int i=0;i<n;i++)cin>>nos[i];
    for(int i=0;i<n;i++)
    {
        if(nos[i]>=3200){nh++;continue;}
        for(int j=1;j<=8;j++)
            if(nos[i]>=(3200-400*j)){col[j]=1;break;}
    }
    int dist = 0;
    for(int i=0;i<9;i++)dist+=col[i];
    int mini = max(dist,1);
    int maxi = dist+nh;
    cout<<mini<<' '<<maxi;
}