#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    string s,ans;
    int len;
    cin>>len;
    cin>>s;
    stack<char>st;
    for(int i=0; i<len; i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if(st.top()=='(' && s[i]==')')
                st.pop();
                else
                st.push(s[i]);
        }
    }
    int x=0,y=0;
    while(!st.empty())
    {
        if(st.top()==')')
            x++;
        else
            y++;
        st.pop();
    }
    for(int i=0; i<x; i++)
        ans+="(";
    ans+=s;
    for(int i=0; i<y; i++)
        ans+=")";
    cout<<ans<<endl;


    return 0;
}
