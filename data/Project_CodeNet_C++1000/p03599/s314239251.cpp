#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    set<double> st1,st2;
    rep(ai, 30)
    {
        rep(bi, 30)
        {
            int tmp = ai * a * 100 + bi * b * 100; 
            if (tmp <= f)
            {
                st1.insert(tmp);
            }
        }
    }
    rep(ci,3000){
        rep(di,3000){
            int tmp = ci * c + di * d;
            if (tmp <= f){
                st2.insert(tmp);
            }
        }
    }
    double den = 0;
    int ret[2];
    for(auto p : st1){
        for(auto p2:st2){
            double noudo = p2 / (p + p2) * 100;
            if (p+p2 <= f && noudo >= den && p/100*e >= p2){
                den = noudo;
                ret[0] = p + p2;
                ret[1] = p2;
            }
        }
    }
    rep(i,2){
        cout << ret[i] << " ";
    }
    cout << endl;
}