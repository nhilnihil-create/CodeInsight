#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int a[100005];
        for(int i=1; i<=n; i++) cin>>a[i];
        int f,ans=0;
        if(n%2==0)
        {
            for(int i=1; i<=n; i++)
                if(a[i]==i) ans++,i++;
        }else{
            f=0;
            for(int i=1; i<n; i++)
                if(a[i]==i){
                    if(i==n-1) f=1;
                    ans++,i++;
                }
            if(!f&&a[n]==n) ans++;
        }
        cout<<ans<<endl;
    }
}
