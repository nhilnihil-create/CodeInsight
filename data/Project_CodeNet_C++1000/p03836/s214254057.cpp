#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int sx,sy,tx,ty;
int main(void){
    cin>>sx>>sy>>tx>>ty;
    for(int i=0;i<(tx-sx);i++){
        cout<<'R';
    }
    for(int i=0;i<(ty-sy);i++){
        cout<<'U';
    }
    for(int i=0;i<(tx-sx);i++){
        cout<<'L';
    }
    for(int i=0;i<(ty-sy);i++){
        cout<<'D';
    }
    cout<<'D';
    for(int i=0;i<(tx-sx+1);i++){
        cout<<'R';
    }
    for(int i=0;i<(ty-sy+1);i++){
        cout<<'U';
    }
    cout<<'L';
    cout<<'U';
    for(int i=0;i<(tx-sx+1);i++){
        cout<<'L';
    }
    for(int i=0;i<(ty-sy+1);i++){
        cout<<'D';
    }
    cout<<'R'<<endl;

}

