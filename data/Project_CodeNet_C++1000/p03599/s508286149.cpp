#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    int ans1 = 100*a, ans2 = 0;
    rep(i,31){
        rep(j,31){
            int water = (a*i + b*j)*100;
            if(water > f) break;
            rep(ii,3001){
                rep(jj,3001){
                    int suger = c*ii + d*jj;
                    if(water + suger > f) break;
                    if(suger*100 > water*e) break;
                    if(ans2*(water+suger) < suger*(ans1+ans2)){
                        ans1 = water;
                        ans2 = suger;
                    }
                }
            }
        }
    }
    cout << ans1+ans2 << " " << ans2 << endl;
}