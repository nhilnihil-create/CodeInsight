#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define sz 300005

int num[sz], visi[sz];

int main()
{
    ios_base:: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int i,j,k,n,r,d;
    cin>>n>>k;

    if(k==1 || k ==2*n-1) cout<<"No\n";
    else if(n==2) cout<<"Yes"<<endl<<"1"<<endl<<"2"<<endl<<"3"<<endl;
    else
    {
        cout<<"Yes"<<endl;
        if(k!=2)
        {
            num[n] =k;
            num[n+1] = k-1;
            num[n-1] = k+1;
            num[n-2] = k-2;

            visi[k]=1, visi[k-1]=1, visi[k+1]=1, visi[k-2]=1;
        }
        else
        {
            num[n] =k;
            num[n+1] = k+1;
            num[n-1] = k-1;
            num[n-2] = k+2;

            visi[k]=1, visi[k+1]=1, visi[k-1]=1, visi[k+2]=1;
        }
        j=1;
        for(i=1; i<2*n; i++)
        {
            while(visi[j]) j++;
            if(!num[i]) num[i] =j ++;
        }

        for(i=1; i<2*n; i++) cout<<num[i]<<endl;
    }
    return 0;
}



