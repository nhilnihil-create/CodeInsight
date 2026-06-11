#include <bits/stdc++.h>
#define pb              push_back
#define mp              make_pair

#define fast_in_out     ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    fast_in_out
    int t,l;cin>>t>>l;
    string s;
    vector<string>con;
    while(t--){
        cin>>s;
        con.pb(s);
    }
    sort(con.begin(),con.end());
    for(auto it=con.begin();it!=con.end();it++)cout<<*it;
    return 0;
}
