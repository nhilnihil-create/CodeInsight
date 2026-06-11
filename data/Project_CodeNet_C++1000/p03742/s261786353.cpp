#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x,y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>x>>y;

    if(abs(x-y)<=1)
        cout<<"Brown"<<endl;
    else
        cout<<"Alice"<<endl;


    return 0;
}
