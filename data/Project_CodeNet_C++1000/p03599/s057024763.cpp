#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main() {
    int a,b,c,d,e,f;
    cin >> a>> b>>c>>d>>e>>f;
    double NOUDO = (double)e/(100+(double)e);
    set<int>W,S;
    rep(i,f){
        rep(j,f){
            int x =100*(a*i+b*j);
            if(x<=f)  W.insert(x);
        }
    }
    rep(i,f){
        rep(j,f){
            int y = c*i+d*j;
            if(y<=f) S.insert(y);
        }
    }
    double MAX = -1.0;
    int ans1,ans2;
    for(auto i:W){
     for(auto j:S){
            int T = i+j;
            if(T==0) break;
            double N = (double)j/(double)T;
            if(N<=NOUDO && T<=f) {
                if(N>MAX){
                    ans1=T;
                    ans2=j;
                    MAX = N;
                }
            }
        }
    }
    cout << ans1 <<' ' << ans2<<endl;
}