#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2e5+100;
bool check(string s)
{
    if(s[0]==s[1]||s[1]==s[2]||s[0]==s[2]) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    if(s.size()<2) cout<<-1<<" "<<-1;
    else if(s.size()==2){
        if(s[0]==s[1]) cout<<1<<" "<<2;
        else cout<<-1<<" "<<-1;
    }
    else{
        for(int i=0;i<s.size()-2;i++){
             string ss=s.substr(i,3);
            if(check(ss)){
                cout<<i+1<<" "<<i+1+2;
                 return 0;
            }
        }
        cout<<-1<<" "<<-1;
    }
    return 0;
}
