#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define plii pair<ll,pii>
#define vi vector<int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mx 100001
#define eps 0.00000000001
#define mod 1000000007
#define pi acos(-1)
#define inf 100000000
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    fio;
        long long int N,L,ok=-1;
    cin >> N >> L;
    vector<long long int> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
        if(L<=a[i]){
            ok = i;
        }
    }

    for(int i=1;i<N;i++){
        if(L<=a[i-1]+a[i]){
            ok = i-1;
            break;
        }
    }

    if(ok==-1){
        cout << "Impossible" << endl;
    }else{
        cout << "Possible" << endl;

        for(int i=0;i<ok;i++){
            cout << i+1 << endl;
        }

        for(int i=N-1;ok<i;i--){
            cout << i << endl;
        }
    }
    return 0;
}

