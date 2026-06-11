#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull long long unsigned
#define vii vector<int>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define pldld pair<long long double, long long double>
#define ff first
#define ss second
#define pb push_back
#define read freopen("alu.txt","r",stdin);
#define write freopen("vorta.txt","w",stdout);
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define PI 2*acos(0.0)

const int MAX=100005, MOD=1000000007;
const ll inf=1e9;

int arr[MAX];
string s[2];
int n;
ll ans=1;
void solve(int i, bool last){
    if(i>=n) return;
    else if(s[0][i]!=s[1][i]){
        if(last) ans*=3;
        else ans*=2;
        ans%=MOD;
        solve(i+2,true);
    }
    else{
        if(last) ans*=1;
        else ans*=2;
        ans%=MOD;
        solve(i+1,false);
    }
}

int main(){

    fastio;
    cin>>n;
    cin>>s[0]>>s[1];
    if(s[0][0]!=s[1][0]){
        ans*=6;
        solve(2,true);
    }
    else{
        ans*=3;
        solve(1,false);
    }
    cout<<ans<<"\n";


}









