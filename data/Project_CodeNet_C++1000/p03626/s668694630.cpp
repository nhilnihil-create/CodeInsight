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
    string s1, s2; cin >> s1 >> s2;

    ll ans = 1;

    if(n == 1){
        cout << 3 << endl;
        return 0;
    }


    int jud;
    int see = 1;

    if(s1[0] != s1[1]){
        jud = 1;
        ans = 3;
    }

    else{
        jud = 2;
        ans = 6;
        see++;
    }

    for(int s = see; s< n-1; s++){

        if(jud == 1){
            if(s1[s] != s1[s+1]){
                ans *= 2;
            }
            else{
                ans *= 2;
                jud = 2;
                s++;
            }
            ans %= 1000000007;
            continue;
        }
        
        if(jud == 2){
            if(s1[s] != s1[s+1]){
                ans *= 1;
                jud = 1;
            }
            else{
                ans *=3;
                s++;
            }
            ans %= 1000000007;
            continue;
        }
    }

    if(jud == 1 && s1[n-1] != s1[n-2] && s1[n-2] != s1[n-3] && n>=3){
        ans *= 2;
        ans %= 1000000007;
    }

    if((n == 2) && jud == 1 && s1[n-1] != s1[n-2]) ans*=2;

    cout << ans << endl;
}