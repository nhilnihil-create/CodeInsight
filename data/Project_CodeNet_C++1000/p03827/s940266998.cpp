#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int ans=0,x=0,n;

    string s;
    cin>>n>>s;

    for(int i=0; i<s.size(); i++){

        if(s[i]=='I')
           x++;
        else x--;

        ans=max(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}
