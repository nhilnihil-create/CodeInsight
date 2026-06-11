#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    bool ok = 0;
    int cnt = 0;
    cin >> n ;
    set<int> si;
    rep(i,n){
        int x;
        cin >> x;
        if(x <= 399) si.insert(0);
        else if( x<= 799) si.insert(1);
        else if(x<=1199) si.insert(2);
        else if(x <=1599) si.insert(3);
        else if(x<=1999) si.insert(4);
        else if(x<=2399) si.insert(5);
        else if(x<=2799) si.insert(6);
        else if(x <= 3199) si.insert(7);
        else {
            //cout << "Yes" << endl;
            ok = 1;
            cnt ++;
        }
    }
    if(!ok){
        cout << si.size() << endl;
        cout << si.size() << endl;
    }else{
        //cout << cnt << endl;
        if(si.size()!=0) cout << si.size()  << endl;
        else cout << 1 << endl;
        cout << si.size()+cnt << endl;
    }
    return 0;
}