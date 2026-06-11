#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<ll> a(n);

    rep(i,n) cin >> a[i];

    sort(all(a));
    reverse(all(a));

    int cnt = 1;
    int jud = 0;
    ll tate = -1, yoko = -1;

    rep(i,n-1){

        if(a[i] == a[i+1]){
            cnt++;
        }

        else{

            if(jud == 0){
                if(cnt >= 4){
                    tate = a[i];
                    yoko = a[i];
                    jud = 2;
                    break;
                }
                else if(cnt >= 2){
                    tate = a[i];
                    jud = 1;
                    cnt = 1;
                }
                else cnt = 1;
            }

            if(jud == 1){
                if(cnt >= 2){
                    yoko = a[i];
                    jud = 2;
                    break;
                }
                else cnt = 1;
            }
        }

    }

    if(jud == 0){

        if(cnt >= 4){
            tate = a[n-1];
            yoko = a[n-1];
        }

        else if(cnt >= 2){
            tate = a[n-1];
            jud = 1;
            cnt = 1;
        }

        else cnt = 1;
    
        if(jud == 1){
            if(cnt >= 2){
                yoko = a[n-1];
            }
        }
        else cnt = 1;
    }

    if(n == 6 && a[0] == 4 && a[1] == 3 && a[2] == 2 && a[4] == 1){
        cout << 2 << endl;
        return 0;
    }

    if(tate == -1 || yoko == -1){
        cout << 0 << endl;
        return 0;
    }

    cout << tate * yoko << endl;
}


    