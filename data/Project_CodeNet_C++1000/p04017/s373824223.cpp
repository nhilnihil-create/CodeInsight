//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
const ll inf=1e18+10;

///---program start---///

int a[arr];
int st[arr][20];
int aa[arr];
int bb[arr];
int ans[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int l;
    cin>>l;
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        cin>>aa[i]>>bb[i];
        aa[i]--;
        bb[i]--;
    }

    int p=n;
    for (int i=n-1;i>=0;i--){
        while ((p==n?a[n-1]+l:a[p])-a[i]>l){
            p--;
        }
        st[i][0]=p;
    }
    for (int j=1;j<20;j++){
        for (int i=0;i<n;i++){
            st[i][j]=(st[i][j-1]==n?n:st[st[i][j-1]][j-1]);
        }
    }
    for (int i=0;i<q;i++){
        int a=aa[i];
        int b=bb[i];
        if (a<=b){
            int res=0;
            for (int i=19;i>=0;i--){
                if (st[a][i]<=b){
                    res+=(1ll<<i);
                    a=st[a][i];
                }
            }
            ans[i]=res+(a!=b);
        }
    }


    p=-1;
    for (int i=0;i<n;i++){
        while (a[i]-(p==-1?a[0]-l:a[p])>l){
            p++;
        }
        st[i][0]=p;
    }
    for (int j=1;j<20;j++){
        for (int i=0;i<n;i++){
            st[i][j]=(st[i][j-1]==-1?-1:st[st[i][j-1]][j-1]);
        }
    }
    for (int i=0;i<q;i++){
        int a=aa[i];
        int b=bb[i];
        if (a>b){
            int res=0;
            for (int i=19;i>=0;i--){
                if (st[a][i]>=b){
                    res+=(1ll<<i);
//                    cout<<a<<" "<<st[a][i]<<"\n";
                    a=st[a][i];
                }
            }
            ans[i]=res+(a!=b);
        }
    }

    for (int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
    }
}
