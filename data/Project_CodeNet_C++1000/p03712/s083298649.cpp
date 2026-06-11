#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int h,w;
    cin >> h >> w;
    
    char a[w][h];
    rep(i,h){
        rep(j,w){
            cin >> a[j][i];
        }
    }

    rep(i,w+2)    cout << '#';
    cout << endl;

    rep(i,h){
        rep(j,w+2){
            if(j==0||j==w+1)    cout << "#";
            else    cout << a[j-1][i];
        }
        cout << endl;
    }

    rep(i,w+2)    cout << '#';
    cout << endl;

    return 0;
}