#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

int main(void)
{
    string S;
    cin >> S;

    string T = "";
    string dream   = "dream"; 
    string erase   = "erase"; 
    string eraser  = "eraser";
    string dreamer = "dreamer"; 

    vector<string> X = {dream,erase,eraser,dreamer};

    //逆順に
    reverse(ALL(S));
    REP(i,4){
        reverse(ALL(X[i]));
    }

//    REP(i,SIZE(S)){
    for (int i = 0; i < S.size();) {
        bool flag = false;
        REP(j,SIZE(X)){
            if(S.substr(i,SIZE(X[j])) == X[j]){
                i += SIZE(X[j]);
                flag = true;
            }
        }
        if(flag == false){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
