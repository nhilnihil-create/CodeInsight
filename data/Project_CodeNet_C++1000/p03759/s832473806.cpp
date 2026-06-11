#include <bits/stdc++.h>
using namespace std;
using ll=long long;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int a,b,c;
    cin>>a>>b>>c;

    if((b-a)==(c-b)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }

}
