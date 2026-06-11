#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define se second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007

typedef long long ll;

void solve(){
    int W,a,b;
    cin>>W>>a>>b;
    int firstL=a;
    int firstR=a+W;
    int secondL=b;
    int secondR=b+W;
    if(firstL>secondR){
        cout<<firstL-secondR<<endl;
    }
    else if(firstR<secondL){
        cout<<secondL-firstR<<endl;
    }
    else cout<<0<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //int t;
    //cin>>t;
    //while(t--)
        solve();
    return 0;
}
