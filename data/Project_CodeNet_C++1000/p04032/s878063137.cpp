#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sfl(i,a,n) for (int i=a;i<n;i++)
#define ufl(i,a,n) for (int i=n-1;i>=a;i--)
#define SZ(x) ((int)(x).size())
#define endl '\n'
typedef long long ll;

ll power(ll a, ll b){
    ll res = 1;
    for(int i = 0; i<b; i++)
        res *= a;

    return res;
}

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main()
{
    init();
    string s;
    cin >>s;
    int len=s.length();
    if(len<2)
    {
        return cout<<"-1 -1",0;
    }
    sfl(i,0,len-1)
    {
        if(s[i]==s[i+1])
            {
                cout <<i+1<<" "<<i+2;
                return 0;
            }

    }
    sfl(i,0,len-2)
    {
        if(s[i]==s[i+2])
        {
            cout <<i+1<<" "<<i+3;
            return 0;
        }
    }
        cout <<"-1 -1";
}
