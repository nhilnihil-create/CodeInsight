#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
typedef long long LL;

int main(){
    IOS;
#ifdef Local
    freopen("data.txt","r",stdin);
#endif//Local
    LL x,y;
    cin>>x>>y;
    if(x<2&&y<2){
        cout<<"Brown\n";
    }
    else if(abs(x-y)>1){
        cout<<"Alice\n";
    }
    else{
        cout<<"Brown\n";
    }
    return 0;
}
