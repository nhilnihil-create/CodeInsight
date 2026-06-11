#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
ifstream in("file.in");
ofstream out("file.out");
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

long long k,p;

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin >> k;
    cout << 50 << '\n';
    for(int i=0;i<k%50;i++){
        cout << 100+k/50-k%50 << ' ';
    }
    for(int i=k%50;i<50;i++){
        cout << 49+k/50-k%50 << ' ';
    }
}
