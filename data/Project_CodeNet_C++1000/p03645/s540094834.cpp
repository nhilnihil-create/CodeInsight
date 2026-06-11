/**
*    author:  souzai32
*    created: 02.08.2020 19:17:59
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    
    int n,m;
    cin >> n >> m;

    vector<tuple<int,int>> ab(m);
    int a,b;
    rep(i,m){
        cin >> a >> b;
        ab.at(i)=make_tuple(a,b);
    }

    sort(ab.begin(),ab.end());
    vector<bool> ship(n);
    bool ans=false;

    rep(i,m){
        if(get<0>(ab.at(i))==1) ship.at(get<1>(ab.at(i)))=true;
        if(get<1>(ab.at(i))==n){
            if(ship.at(get<0>(ab.at(i)))) ans=true;
        }
    }

    if(ans) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}