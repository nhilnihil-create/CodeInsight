#include<bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define all(v) (v).begin(),(v).end() 
#define endl "\n"
#define int long long int
#define ll long long
#define ld long double
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
const int mod = 1000000007;
const int N=200005;
const int inf=1e18;
vector<vector<int>>adj(N);

bool isprime(int n){for(int i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
int factorial(int n){return (n==1 || n==0) ? 1:n*factorial(n-1);} 
int gcd(int a,int b){if (a==0)return b;return gcd(b%a,a);}
int lcm(int a,int b){return (a/gcd(a,b)*b);}
int max(int a,int b){int sol=a>b?a:b;return sol;}
int min(int a,int b){int sol=a<b?a:b;return sol;} 

void fun(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}


signed main(){
    flash;
    fun();
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        while(n>1){
            n/=2;
            cnt++;
        }
        cout<<pow(2,cnt);
    }
    return 0;
}