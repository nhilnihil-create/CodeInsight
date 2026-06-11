#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001000
#define mod 1000000007
#define pi 3.1415926535
using namespace std;

int main(void){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ake = 0;
    ll toji = 0;
    rep(i,n){
        if(s[i] == '('){
            ake++;
        }
        else{
            if(ake > 0) ake--;
            else toji++;
        }
    }
    rep(i,toji) cout<<'(';
    cout<<s;
    rep(i,ake) cout<<")";
    cout<<endl;
}