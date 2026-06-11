#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    vector<int> water(31, 0);
    water[0] = 1;
    rep(i, 31){
        if (i < a) continue;
        if (water[i-a] == 1) water[i] = 1;
    }
    rep(i, 31){
        if (i < b) continue;
        if (water[i-b] == 1) water[i] = 1;
    }
    vector<int> suger(3001, 0);
    suger[0] = 1;
    rep(i, 3001){
        if (i < c) continue;
        if (suger[i-c] == 1) suger[i] = 1;
    }
    rep(i, 3001){
        if (i < d) continue;
        if (suger[i-d] == 1) suger[i] = 1;
    }

    set<int, greater<int>> sset;
    rep(i, 3001){
        if (suger[i] == 1) sset.insert(i);
    }


    double rate = 0;
    int ans_s = 0;
    int ans_w = 0;
    rep1(i, 30){
        if (water[i] == 1){
            int limit = i*e;
            limit = min(limit, f-i*100);
            if (limit <= 0) continue;            
            auto suger = sset.lower_bound(limit);
            //cout << i*100 << ":" << *suger << endl;
            double trate = (double)*suger / (double)i;
            if (trate >= rate){
                ans_w = i*100; ans_s = *suger;
                rate = trate;
            }
        }
    }

    cout << ans_w+ans_s << " " << ans_s << endl; 

}

