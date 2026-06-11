#include<iostream>
#include<stack>
#include<vector>
#define ll long long
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 200004

using namespace std;

string s;
ll minlength[N];
ll n;
string ans;
ll epomeno[N][26];

ll first_occurence(ll cur,ll id)
{
    return epomeno[cur][id];
}

ll calc(ll cur)
{
    if(cur > n)
        return 0;
    if(cur == n)
        return 1;

    if(minlength[cur])
        return minlength[cur];

    minlength[cur] = n-cur+1;

    rep(i,0,26)
    {
        ll goes = first_occurence(cur,i);

        minlength[cur] = min(minlength[cur],calc(goes+1)+1);
    }

    return minlength[cur];
}

void solve(ll cur,ll pos)
{
    if(cur >= n)
        return;

    rep(i,0,26)
    {
        ll goes = first_occurence(cur,i);

        if(minlength[goes+1]+1==minlength[cur])
        {
            ans[pos]=i+'a';
            solve(goes+1,pos+1);
            break;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.size();

    rep(i,0,26)
    {
        epomeno[n][i]=n;
        for(int j = n-1;j>=0;j--)
        {
            if(s[j]-'a'==i)
                epomeno[j][i]=j;
            else
                epomeno[j][i]=epomeno[j+1][i];
        }
    }

    calc(0);

    rep(i,0,minlength[0])
        ans += "a";

    solve(0,0);

    cout << ans;

    return 0;
}
