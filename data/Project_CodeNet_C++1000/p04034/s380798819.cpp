#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,M; cin>>N>>M;
    vector<vector<int>> ope(M,vector<int>(2));
    rep(m,0,M) cin>>ope.at(m).at(0)>>ope.at(m).at(1);

    set<int> redInBox;
    redInBox.insert(0);
    vector<int> balls(N,1);

    for(auto o:ope){
        int fromB=o.at(0)-1,toB=o.at(1)-1;
        if(redInBox.count(fromB)){
            redInBox.insert(toB);
        }
        if(balls.at(fromB)==1) redInBox.erase(fromB);

        balls.at(fromB)--;
        balls.at(toB)++;
    }

    cout<<redInBox.size()<<endl;
}