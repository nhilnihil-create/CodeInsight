#include <bits/stdc++.h>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))

typedef long long ll;


ll N, x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>x;
    vector<ll> vi;
    for(int i=0;i<N;++i){
        ll a;
        cin>>a;
        vi.pb(a);
    }
    ll sum=0;
    for(int i=1;i<N;++i){
        if(vi[i]+vi[i-1]>x){
            ll dif=(vi[i]+vi[i-1])-x;
            if(vi[i]>=dif){
                vi[i]-=dif;
                sum+=dif;
            }
            else{
                sum+=vi[i];
                dif-=vi[i];
                vi[i]=0;
                vi[i-1]-=dif;
                sum+=dif;
            }
        }
    }
    cout<<sum;
    return 0;
}
