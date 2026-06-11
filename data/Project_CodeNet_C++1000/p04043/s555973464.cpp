#include<bits/stdc++.h>
using namespace std;
int cnt[5];
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;
    if(cnt[5]==2&&cnt[7]==1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
