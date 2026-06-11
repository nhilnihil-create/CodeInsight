#include <bits/stdc++.h>

typedef  long long ll ;

using namespace std;

int tox[]={0,0,1,-1};
int toy[]={1,-1,0,0};
int num[int(1e5+4)],red[int(1e5+4)];
int main()
{
    int n,m;
    cin>>n>>m;
    red[0]=1;
    while(m--){
        int i,x;
        cin>>i>>x;
        i--,x--;
        if(red[i])
            red[x]=1;
        num[i]--;
        num[x]++;
        if(num[i]==-1)
            red[i]=0;
    }
    int res=0;
    for (int i = 0; i < n; ++i)
    {
        res+=red[i];
    }
    cout<<res<<endl;
    return 0;
}