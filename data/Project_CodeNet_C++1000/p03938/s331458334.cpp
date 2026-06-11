#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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
#define eps 1e-11
#define DEBUG(x) cerr << #x << " = " << x << endl
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

const int MAX = 2e5 + 5, MOD = 1e9 + 7  , MAXLG = log2(MAX)+1;
const ll inf = 1e18 + 5;

int arr[MAX];
int main(){

    fastio;
    int n;
    cin >> n;
    vector<int> a(n+5), b(n+5);
    int gap = n+5;
    for(int i=1; i<=n; i++) a[i] = gap * i;
    for(int i=n; i>0; i--) b[i] = gap * (n-i+1);
    
    int inc = 1;
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        b[p] += inc;
        inc++;
    }

    for(int i=1; i<=n; i++) cout << a[i] << " ";
    cout << "\n";
    for(int i=1; i<=n; i++) cout << b[i] << " ";
    cout << "\n";

    // for(int i=1; i<=n; i++) cout << a[i] + b[i] << " ";
    // cout << "\n";
}