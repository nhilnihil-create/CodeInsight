#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int> c(11);
    for(int i=0;i<3;i++){
        int x;
        cin>>x;
        c[x]++;
    }
    if((c[5]==2)&&(c[7]==1)) cout<<"YES";
    else cout<<"NO";
}
