#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    char a,b;
    cin>>a>>b;
    if((a=='H'&&b=='H')||(a=='D'&&b=='D'))cout<<'H'<<endl;
    else cout<<'D'<<endl;

    return 0;
}
