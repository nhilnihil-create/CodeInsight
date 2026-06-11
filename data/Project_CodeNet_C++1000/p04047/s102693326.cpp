/**
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh (H S T U).
      Name        : Sourav Roy (Shuvo)
      Department  : Computer Science and Engineering (Batch - CSE'19)
      Email       : souravkumarroy813965@gmail.com
**/


#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define all(a) a.begin(),a.end()

void solve()
{
    vector <int> v;
    int n,i,x,sum=0,cn=0;
    cin >> n;
    for(i=0; i<2*n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    sort(all(v));

    for(i=0; i<2*n; i+=2)
    {
        sum += v[i];

    }
    cout << sum << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    solve();

}
/**
Test Case :

**/