#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

#define N 4e7
#define nl "\n"
#define f first
#define s second
#define pi acos(-1.0)
#define MOD 1000000007
#define pb push_back


typedef long long ll;
typedef double db;

using namespace std;

int v[30];

int main()
{
    io;
    //freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);

    ///Let the showdown begin

    string s;
    cin >> s;

    for(int i=0; i<s.size(); i++)
    {
        v[s[i] - 'a']++;
    }
    int flag = 0;

    for(int i=0; i<30; i++)
    {
        if(v[i] % 2 ==1)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        cout << "Yes" << nl;
    else
        cout << "No" << nl;

    ///Happily DONE
    return 0;
}
