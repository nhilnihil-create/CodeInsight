#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int x,a,b;
    cin>>x>>a>>b;
    if(a>=b)cout<<"delicious"<<endl;
    else if(a+x>=b)cout<<"safe"<<endl;
    else cout<<"dangerous"<<endl;

    return 0;
}

