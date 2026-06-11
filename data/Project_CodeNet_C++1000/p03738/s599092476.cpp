#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

#define N 4e7
#define nl "\n"
#define f first
#define s second
#define pi acos(-1.0)
#define MOD 1000000007
#define pb push_back
#define vector<int> VI;
#define vector<long long> VII;

typedef long long ll;
typedef double db;

using namespace std;

int main()
{
    io;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt" , "w" , stdout);

    ///Let the showdown begin

    string s1,s2;

    cin >> s1 >> s2;

    int sz1=s1.size();
    int sz2=s2.size();

    if(sz1>sz2)
        cout << "GREATER" << nl;
    else if(sz1<sz2)
        cout << "LESS" << nl;
    else
    {
        if(s1.compare(s2) < 0)
            cout << "LESS" << nl;
        else if(s1.compare(s2) > 0)
            cout << "GREATER" << nl;
        else if(s1.compare(s2) == 0)
            cout << "EQUAL" << nl;
    }
    ///Happily DONE

    return 0;
}
