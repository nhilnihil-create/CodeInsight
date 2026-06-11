/**
*    author:  souzai32
*    created: 07.08.2020 23:51:01
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    vector<bool> p(n);
    vector<int> ball(n,1);
    p.at(0)=true;
    int x,y;
    rep(i,m){
        cin >> x >> y;
        x--;
        y--;
        if(p.at(x)) p.at(y)=true;
        ball.at(x)--;
        ball.at(y)++;
        if(ball.at(x)==0) p.at(x)=false;
    }

    int count=0;
    rep(i,n) if(p.at(i)) count++;

    cout << count << endl;

    return 0;
}