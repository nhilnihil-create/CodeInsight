#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll arr[120];
ll nCr(ll n, ll r)
{
    ll C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1]);

    }
    return C[r];
}

bool cmp(pair<long double,ll>&l,pair<long double,ll> &r)
{
    if(l.first<r.first)
        return 1;
    if(l.first>r.first)
        return 0;
    if(l.second<r.second)
        return 1;
    return 0;
}



ll ans2 = 0,tmp=0,ave= 0;
ll COM(ll n, ll k){
    ll num=1;
    for(int i=0;i<k;i++) {
        num *= n-i;
        num /= (1+i);
    }
    return num;
}
vector<ll>V;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    long double sum=0,cnt=0;
    vector<pair<long double,ll> >ans;
    ll n,a,b;
    cin>>n>>a>>b;
    for(int i=0; i<n; i++)
        {cin>>arr[i];
        V.push_back(arr[i]);
        }
    sort(arr,arr+n);
    for(int i=n-1; i>=0; i--)
    {
        sum+=arr[i];
        cnt++;
        if(cnt>b)
            break;
        if(cnt>=a)
        {
            int t=0;
            for(int j=i-1; j>=0; j--)
            {
                if(arr[i]==arr[j])
                    t++;
            }
            int t2=0;
            for(int j=i; j<n; j++)
            {
                if(arr[i]==arr[j])
                    t2++;
            }
            ans.push_back({sum/cnt,nCr(t2+t,t2)});

        }
    }

    sort(V.begin(),V.end());


     ll id1 = lower_bound(V.begin(), V.end(), V[n-a])-V.begin();
    if(id1!=n-a) {
        ll id2 = lower_bound(V.begin(), V.end(), V[n-a]+1)-V.begin();
        ans2 += COM(id2-id1, id2-(n-a));
        //cout << id2-id1 << " " << id2-(N-A) << " " << COM(id2-id1, id2-(N-A)) << endl;
        if(V[n-a]==V[n-1]) {
            for(int i=n-a-1;i>=max(n-b, id1);i--) {
                tmp = COM(id2-id1, id2-i);
                //if(tmp<0) tmp += MOD;
                ans2 += tmp;
                //cout << id2-id1 << " " << id2-i << " " << tmp << endl;
            }
        }
    }





   





    sort(ans.begin(),ans.end(),cmp);
    int sz=ans.size();
    cout<<setprecision(6)<<fixed<<ans[sz-1].first<<endl;
    //cout<<ans[sz-1].second<<endl;
    cout << setprecision(18) << max(1LL, ans2) << endl;
    return 0;
}

