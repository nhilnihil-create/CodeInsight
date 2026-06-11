#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=1;
    cin>>n;
    map<int,int>m;

    for(int i=2;i <=n;i++){
       int cpy = i;
       for(int j=2;j*j<=cpy;j++){
            if(cpy%j==0){
                while(cpy%j==0){
                    m[j]++;
                    cpy = cpy/j;
                }
            }
       }
    if(cpy!=1){
        m[cpy]++;
    }

    }
    int j =1;
    tr(it,m){
            j = (j*(it->second +1))%mod;
    }
    cout<<j<<endl;

    }


















