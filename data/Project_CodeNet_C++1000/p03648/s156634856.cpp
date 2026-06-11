#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e9 +7;
signed main(){
    int k,p,q;;
    cin >>k;
    p=k/50;q=k%50;
    cout <<50<<endl;
    for(int i=0;i<q;i++){
        cout <<50-i+p<<' ';
    }
    for(int i=q;i<50;i++){
        cout <<49-i+p<<' ';
    }




    return 0;
}