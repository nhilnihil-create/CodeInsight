#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,ans=0,a,b,maxA=0;

    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>a>>b;

        if(a>maxA){
            ans=a+b;
            maxA=a;
        }
    }

    cout<<ans<<endl;

    return 0;
}