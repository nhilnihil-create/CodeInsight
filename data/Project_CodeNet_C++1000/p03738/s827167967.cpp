#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define Opy ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;

int main()
{
    //Opy;

/*-------------------------------------------------
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
-------------------------------------------------*/
    string A, B;

    cin>> A>> B;

    if(A.size() > B.size()) cout<< "GREATER\n";

    else if(A.size() < B.size()) cout<< "LESS\n";

    else
    {
        if(A > B) cout<< "GREATER\n";

        else if(A < B) cout<< "LESS\n";

        else cout<< "EQUAL\n";
    }

    return 0;
}
