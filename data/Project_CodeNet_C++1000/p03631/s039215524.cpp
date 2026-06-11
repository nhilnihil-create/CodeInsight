#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string a;string b;
    cin>>a;
    b=a;
    reverse(b.begin(),b.end());
    if (a==b){
        cout<<"Yes";
    }else cout<<"No";
    return 0;
}
