#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

//snippets:tmp,cl,cvl,cs,co,coy,con,cov

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<char>a(n);
    rep(i,4){
        if(i/2==0) a[0]='S';
        else a[0]='W';
        if(i%2==0) a[1]='S';
        else a[1]='W';
        repi(j,2,n){
            if(s[j-1]=='o'){
                if(a[j-1]=='S') a[j]=a[j-2];
                else a[j]=(a[j-2]=='S' ?'W' :'S');
            }else{
                if(a[j-1]=='S') a[j]=(a[j-2]=='S' ?'W' :'S');
                else a[j]=a[j-2];
            }
        }
        if((s[n-1]=='o'&&a[n-1]=='S')||(s[n-1]=='x'&&a[n-1]=='W')){
            if(a[n-2]!=a[0]) continue;
        }else{
            if(a[n-2]==a[0]) continue;
        }
        if((s[0]=='o'&&a[0]=='S')||(s[0]=='x'&&a[0]=='W')){
            if(a[n-1]!=a[1]) continue;
        }else{
            if(a[n-1]==a[1]) continue;
        }
        rep(i, a.size() - 1) cout << a[i];
        cout << a[a.size()-1] << endl;
        return 0;
    }
    cout << -1 << endl;
}