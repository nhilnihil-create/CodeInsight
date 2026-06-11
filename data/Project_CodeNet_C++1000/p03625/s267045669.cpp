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
    ll N;
    cin >> N;

    vector<ll> A(N);

    for(ll i = 0;i < N;i++)
        cin >> A.at(i);

    ll k1=0,k2=0;

    SORT(A);

    for(ll i = 0;i < N -1;i++){
        if(A.at(i) == A.at(i+1)){
            if(k1 <= k2)
                k1 = A.at(i);
            else
            {
                k2 = A.at(i);
            }
            i++;
        }
    }


    cout << k1 * k2 << endl;
    return 0;
}
