#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<" = "<<x<<endl;
#define dbg_v(v,n) {cerr<<#v<<" = [";for(int III=0;III<=n;III++)cerr<<v[III]<<(III!=n?",":"]\n");}
#define ll long long
#define ld long double
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define Nmax 102
using namespace std;

int n,fr[Nmax],x,mx,mn;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> x;
        fr[x]++;
        if (x > mx) mx = x;
    }
    if (mx==1){
        if (n==2) cout << "Possible\n";
        else cout << "Impossible\n";
        return 0;
    }
    mn = (mx+1) / 2;
    if (mx%2==0) mn++;
    for (int i=mx;i>=mn;i--){
        if (fr[i] < 2){
            cout << "Impossible\n";
            return 0;
        }
    }
    if (mx%2==0){
        mn--;
        if (fr[mn]!=1){
            cout << "Impossible\n";
            return 0;
        }
    }
    else{
        if (fr[mn]!=2){
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i=mn-1;i>=1;i--){
        if (fr[i]){
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << "Possible\n";
    return 0;
}
