/*
...........__________                                                                           ___  __
.............|       |                                                                           |   /
.............|       |                                                                           |  /
.............|       |                               |                         __                | /      _______
.............|_______|  _______            _______   |______   ________   /|  /  |               |/       |      |
.............| \               | |      | |          |      |          | / | /   |               |\       |
.............|  \       _______| |      | |_______   |      |   _______|   |/    |               | \      |
.............|   \      |      | |      |         |  |      |  |       |   |     |               |  \     |
...........__|    \__|  |______| |______| ________|  |      |_ |_______|   |     |__|           _|   \__ _|        .

*/
#include<bits/stdc++.h>
using namespace std ;
#define int                 long long
#define ull                 unsigned long long int
#define ld                  long double
#define vi                  vector<int>
#define vii                 vector<pair<int,int>>
#define vvi                 vector<vector<int>>
#define pii                 pair<int,int>
#define prec(x)             fixed<<setprecision(15)<<x
#define all(x)              x.begin(),x.end()
#define rall(x)             x.rbegin(),x.rend()
#define rev(x)              reverse(x.begin(),x.end())
#define mset(a,b)           memset(a,b,sizeof(a))
#define mcpy(a,b)           memcpy(a,b,sizeof(a))
#define fo0(i,n)            for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n)            for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b)           for(int i=a,i##end=b;i<=i##end;i++)
#define foe(i,x)            for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)
#define fre(i,x)            for(__typeof((x).rend())i=(x).rbegin();i!=(x).rend();++i)
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0)
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
const int inf=1e18;const int mod=1e9+7;const int N=2e5+9;
void read_And_write(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

void raushan_kumar(){
    int d=0,e=0,f=0,g=0,p=0,w=0,flag=0,ans=0,res=0,cnt=0,sum=0;double f1=0.0,f2=0.0,f3=0.0;
    int n;cin>>n;n*=2;int a[n];fo0(i,n) cin>>a[i];
    sort(a,a+n);
    
    for(int i=0;i<n;i+=2)
    	sum+=a[i];
    cout<<sum;
}

int32_t main()
{
    fast;int t=1;
    // cin>>t;
    while(t--){raushan_kumar();}
}