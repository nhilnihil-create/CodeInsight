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

///---program start---///

#define arr (int)(1e5+10)

map<vi,bool> win;

bool get_win(vi a)
{
    if (a.empty()){
        return 1;
    }
    if (win.count(a)){
        return win[a];
    }
    bool res=0;
    vi b;

    b=a;
    b.pop_back();
    res|=(!get_win(b));

    b=a;
    reverse(all(b));
    while (!b.empty()&&b.back()==1){
        b.pop_back();
    }
    reverse(all(b));
    for (auto& i:b){
        i--;
    }
    res|=(!get_win(b));
    win[a]=res;

    return res;
}

string solve(int a)
{
    if (a==1){
        return "First";
    }
    else{
        return "Second";
    }
}

bitset<arr> reversed(bitset<arr> a)
{
    bitset<arr> res;
    for (int i=0;i<arr;i++){
        res[i]=a[arr-i-1];
    }
    return res;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    bool debug=0;
    int n;
    vi a;

    if (debug){
        srand(time(0));
        n=5;
        a.resize(n);
        for (auto& i:a){
            i=rand()%5+1;
        }
    }
    else{
        cin>>n;
        a.resize(n);
        for (auto& i:a){
            cin>>i;
        }
    }
//    cout<<n<<"\n";
//    for (auto i:a){
//        cout<<i<<" ";
//    }
//    cout<<"\n";

    sort(all(a));
//    cout<<"naive :: "<<solve(get_win(a))<<"\n";

    bitset<arr> wins;
    bitset<arr> buf;
    bitset<arr> all_gamebale;
    for (auto& i:a){
        if (i>=arr){
            i=(arr-2)+((arr-2)%2!=i%2);
        }
    }
    sort(all(a));
    for (int i=a[0];i>=0;i-=2){
        wins[i]=1;
    }
    for (int i=0;i<=a[0];i++){
        all_gamebale[i]=1;
    }
    for (int i=1;i<n;i++){
//        cout<<"before i :: "<<reversed(wins)<<"\n";
        buf=wins;
        wins=wins^all_gamebale;
        for (int j=a[i-1]+(a[i-1]%2!=a[i]%2);j<=a[i];j+=2){
            wins[j]=1;
        }
        for (int j=a[i-1];j<arr&&j<=a[i];j++){
            all_gamebale[j]=1;
        }
        wins=wins|((buf&(wins>>1))>>1);
//        cout<<" after i :: "<<reversed(wins)<<"\n";
    }


    cout<<solve(wins[0])<<"\n";
}
