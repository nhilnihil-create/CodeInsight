#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    string s;cin>>s;
    int n=s.size();

    n--;

    while(s.substr(0,n/2)!=s.substr(n/2,n/2)){
        n--;
    }
    // cout<<s.substr(0,n/2)<<endl;
    // cout<<s.substr(n/2,n/2)<<endl;
    cout<<n-1<<endl;
    
}
