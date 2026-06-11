#include<bits/stdc++.h>
#define Abra_Ka_Dabra ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    Abra_Ka_Dabra

    map<char, int> x;
    char n;
    while(cin>>n) x[n]++;
    bool flag = true;
    for(auto i=x.begin(); i!=x.end(); i++){
        if(i->second & 1) flag = false;
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
