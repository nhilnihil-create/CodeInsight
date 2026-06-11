#include <bits/stdc++.h>
#define pb              push_back
#define fast_in_out     ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    fast_in_out
    string s;
    cin>>s;
    vector<char>con;
    for(int i=0;i<(int)(s.size());i++){
        if(s[i]=='B'){
            if(!con.empty())con.pop_back();
        }
        else con.pb(s[i]);
    }
    for(auto it=con.begin();it!=con.end();it++)cout<<*it;
    return 0;
}
