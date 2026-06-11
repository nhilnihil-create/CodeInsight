#include<bits/stdc++.h>
#define int long long
#define log(x,b) (log(x)/log(b))
using namespace std;

int32_t main()
{
    int a,b,x;
    cin>>a>>b>>x;
    if(b==0)cout<<1<<endl;
    else if(a==0)cout<<b/x+1<<endl;
    else{
        a--;
        cout<<b/x-a/x<<endl;
    }

    return 0;
}
