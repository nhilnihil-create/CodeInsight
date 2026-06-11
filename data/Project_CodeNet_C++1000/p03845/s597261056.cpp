#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,t[101],m,p,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>p>>x;
        int ans=0;
        for(int j=1;j<=n;j++){
            if(p==j){
                ans+=x;
            }
            else
            ans+=t[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
