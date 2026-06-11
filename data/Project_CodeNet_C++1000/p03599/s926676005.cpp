#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){

    int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;

    vector<int> water,sugar;
    int i = 0, j;
    while(i*a*100 <= f){
        j = 0;
        while(i*a*100 + j*b*100 <= f){
            int o = i*a*100 + j*b*100;
            if(i+j != 0) {
                water.push_back(o);
            }
            j++;
        }
        i++;
    }
    int p = 0,q;
    while(c*p <= f){
        q = 0;
        while(c*p + d*q <= f){
            int o = c*p + d*q;
            sugar.push_back(o);
            q++;
        }
        p++;
    }
    int wa_size = water.size();
    int su_size = sugar.size();
    int ans_sum = 0;
    int ans_sug = 0;
    ld dens = -1.0;
    rep(x,wa_size)rep(y,su_size){

            int sum = water.at(x)+sugar.at(y);
            if(sum <= f && sugar.at(y) <= water.at(x)*e/100){
                if(sugar.at(y)/double(sum) > dens){
                    dens = sugar.at(y)/double(sum);
                    ans_sum = sum;
                    ans_sug = sugar.at(y);
                } 
            }
    }
    cout << ans_sum sp ans_sug << endl;
    return 0;
}
