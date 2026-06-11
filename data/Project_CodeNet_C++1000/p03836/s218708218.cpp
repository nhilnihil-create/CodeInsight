//苦手 解説AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx-sx;
    int dy = ty-sy;
    string m1;
    string m2;
    string m3;
    string m4;
    if(dx>0)
        rep(i,dx){
            m1+='R';
            m2+='L';
            m3+='R';
            m4+='L';
        }
    else if(dx<0)
        rep(i,-dx){
            m1+='L';
            m2+='R';
            m3+='L';
            m4+='R';
        }
    if(dy>0)
        rep(i,dy){
            m1+='U';
            m2+='D';
            m3+='U';
            m4+='D';
        }
    else if(dy<0)
        rep(i,-dy){
            m1+='D';
            m2+='U';
            m3+='D';
            m4+='U';
        }
    m3.insert(0,"DR");
    m3.insert(m3.size(),"UL");
    m4.insert(0,"UL");
    m4.insert(m4.size(),"DR");
    cout << m1 << m2 << m3 << m4 << endl;
	return 0;
}