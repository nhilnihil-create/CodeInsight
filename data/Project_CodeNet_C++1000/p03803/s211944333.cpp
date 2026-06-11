#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;
    if(a==b)cout<<"Draw"<<endl;
    else if(a==1||b==1){
        if(a==1)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    else {
        if(a>b)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }

    return 0;
}
