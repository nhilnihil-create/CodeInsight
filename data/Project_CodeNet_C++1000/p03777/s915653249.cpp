#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200010],vis[200010];
vector<int>v;
int main(){
    char a,b;
    cin>>a>>b;
    if(a=='H')
    {
        if(b=='H')cout<<'H';
        if(b=='D')cout<<'D';
    }
    else 
    {
        if(b=='H')cout<<'D';
        if(b=='D')cout<<'H';
    }
    return 0;
}
