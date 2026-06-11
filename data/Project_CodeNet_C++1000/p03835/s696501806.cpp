#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k,s,ans=0;

    cin>>k>>s;

    for(int i=0; i<=k; i++){
        for(int j=0; j<=k; j++){

            int x = s-i-j;
            if(x>=0 && x<=k)
                ans++;
        }
    }

    cout<<ans<<endl;
}
