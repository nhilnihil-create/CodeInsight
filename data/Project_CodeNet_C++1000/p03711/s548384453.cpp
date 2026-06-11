#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,sum = 0,tmp,cnt = 0,i;
    vector<int>v;
    map<int,int>mp1,mp2;
    mp1[1] = 1;
    mp1[3] = 1;
    mp1[5] = 1;
    mp1[7] = 1;
    mp1[8] = 1;
    mp1[10] = 1;
    mp1[12] = 1;
    mp2[4] = 1;
    mp2[6] = 1;
    mp2[9] = 1;
    mp2[11] = 1;
    cin>>a>>b;
    if(a==2 || b==2)
        cout<<"No\n";
    else if((mp1[a]==1 && mp1[b]==1) || (mp2[a]==1 && mp2[b]==1))
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
