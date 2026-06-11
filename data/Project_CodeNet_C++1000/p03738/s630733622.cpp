#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string a,b;
    cin >> a >> b;

    if(a.size() > b.size())
    {
        cout << "GREATER" << endl;
    }

    else if(a.size() < b.size())
    {
        cout << "LESS" << endl;
    }

    else
    {
        if(b[0] < a[0])
        {
            cout << "GREATER" << endl;
        }
        else if(a[0] < b[0])
        {
            cout << "LESS" << endl;
        }
        else
        {
            cout << "EQUAL" << endl;
        }
    }
}