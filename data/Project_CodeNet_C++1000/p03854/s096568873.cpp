#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define int long long
#define endl '\n'
#define all(a)                   (a).begin(),(a).end()

#define Unique(A)                (A).resize(distance((A).begin(),unique(all((A)))))

using namespace std;

const int N = 2e5 + 77;

string s ;
int n ; 
int32_t main()
{
    fast;
    cin >> s;
    bool ok = true;
    
    regex R ("(dream|erase|dreamer|eraser)*");

    ok = (regex_match(s,R));
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}