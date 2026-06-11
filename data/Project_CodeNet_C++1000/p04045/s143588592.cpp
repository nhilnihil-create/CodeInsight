

#include<bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);

vector<int>d(10,1);

bool isvalid(int ans)
{
    while(ans>0)
    {
        if(d[ans%10]==0) return false;

        ans/=10;
    }

    return true;
}

int main()
{
    speed;

    int n,k,x;
    cin>>n>>k;

    for(int i=0;i<k;i++) 
    {
        cin>>x;
        d[x]=0;
    }

    int ans=n;

    while(ans<=10*n && !isvalid(ans)) ans++;

    cout<<ans<<"\n";
}