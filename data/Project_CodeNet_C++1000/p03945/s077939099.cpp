#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    string s;
    cin>>s;
    int res=1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]!=s[i+1])res++;
    }
    cout<<res-1<<endl;

    return 0;
}
