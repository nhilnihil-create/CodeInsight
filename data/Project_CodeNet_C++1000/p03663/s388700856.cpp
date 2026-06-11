#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define rd(x) cin >> x;
#define rda(a,n) for(int i=1;i<=n;i++) cin >> a[i];
#define wr(x) cout << x << ' ';
#define wrl(x) cout << x << '\n';
#define wra(a,n) for(int i=1;i<=n;i++) cout << a[i] << ' '; cout << '\n';
#define lg length()
#define pb push_back
ifstream in("file.in");
ofstream out("file.out");
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005
#define int long long

char ans;
vector <int> q;
int n,t=1,k=1,x=10;

int32_t main(){
    ios_base :: sync_with_stdio(0);
    while(k<10){
        cout << "? " << x << endl;
        cin >> ans;
        if(ans=='Y') k++,x*=10;
        else break;
    }
    if(k==10){
        for(int i=1;i<=1e9;i*=10){
            cout << "? " << 2*i << endl;
            cin >> ans;
            if(ans=='Y'){
                cout << "! " << i << endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=k-1;i++){
        int l=0,r=9;
        if(i==1) l=1;
        else t*=10;
        while(l!=r){
            int mid=(l+r+1)/2;
            cout << "? " << 10*n+mid << endl;
            cin >> ans;
            if(ans=='N') r=mid-1;
            else l=mid;
        }
        n*=10; n+=l;
    }
    if(n){
        for(int i=0;i<=9;i++){
            cout << "? " << 100*n+10*i+1 << endl;
            cin >> ans;
            if(ans=='Y'){
                n*=10; n+=i;
                cout << "! " << n << endl;
                return 0;
            }
        }
    }
    else{
        for(int i=1;i<=9;i++){
            cout << "? " << 100*n+10*i+1 << endl;
            cin >> ans;
            if(ans=='Y'){
                n*=10; n+=i;
                cout << "! " << n << endl;
                return 0;
            }
        }
    }
}
