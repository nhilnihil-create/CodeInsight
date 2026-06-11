#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
 
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);


int sa[100005];
int sb[100005];
int ta[100005];
int tb[100005];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S,T;
    cin >> S >> T;
    rep(i,S.size()){
        sa[i+1] = sa[i];
        sb[i+1] = sb[i];
        if(S[i]=='A')sa[i+1]++;
        else sb[i+1]++;
    }
    rep(i,T.size()){
        ta[i+1] = ta[i];
        tb[i+1] = tb[i];
        if(T[i]=='A')ta[i+1]++;
        else tb[i+1]++;
    }
    int q;
    cin >> q;
    rep(i,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int sanum = sa[b]-sa[a-1];
        int sbnum = sb[b]-sb[a-1];
        int tanum = ta[d]-ta[c-1];
        int tbnum = tb[d]-tb[c-1];
        sanum %= 3;
        sbnum %= 3;
        tanum %= 3;
        tbnum %= 3;
        if(sanum==0);
        else if(sanum==1)sbnum+=2;
        else if(sanum==2)sbnum++;
        if(tanum==1)tbnum+=2;
        else if(tanum==2)tbnum++;
        sbnum %= 3;
        tbnum %= 3;
        if(sbnum==tbnum)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}