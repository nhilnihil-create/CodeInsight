#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,beg,fin;
    cin>>n>>m;

    int num_load[n]={};
    for(i = 0; i < m; i++)
    {
        cin>>beg>>fin;
        num_load[beg-1]++;
        num_load[fin-1]++;
    }

    for(i = 0; i < n; i++) cout<<num_load[i]<<endl;
}