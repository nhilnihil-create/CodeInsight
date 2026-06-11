#include<bits/stdc++.h>
#define int long long
#define log(x,b) (log(x)/log(b))
using namespace std;

string s;

int32_t main()
{
    int n;
    cin>>n>>s;
    int cnt=0;
    int res=0;
    for(int i=0;i<n;i++){
        if(s[i]=='I'){cnt++;res=max(res,cnt);}
        else cnt--;
    }

    cout<<res<<endl;

    return 0;
}
