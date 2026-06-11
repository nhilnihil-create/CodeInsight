#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define ll              long long

#define vi              vector<int>
#define pb              push_back
#define mp              make_pair

#define ff              first
#define ss              second

#define fast_in_out     ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
bool arr[11];
int main()
{
    fast_in_out
    vi con,rem;
    //freopen ("myfile.txt","w",stdout);
    int n,k,x;cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>x;
        con.pb(x);
    }
    int t;

    while(1){
        t=n;
        int i=0;

        while(t/10){
            rem.pb(t%10);
            t/=10;
        }
        rem.pb(t);
        //for(auto it1=rem.begin();it1!=rem.end();it1++)cout<<*it1<<'\t';
        //break;
        bool chosen=true;
        for(auto it1=rem.begin();it1!=rem.end();it1++){
            for(auto it2=con.begin();it2!=con.end();it2++){
                if(*it1==*it2){
                    chosen=false;
                    break;
                }
            }
            if(!chosen)break;

        }
        if(chosen){
            cout<<n<<'\n';
            return 0;
        }
        //cout<<n<<'\t';
        n++;
        while(!rem.empty())rem.pop_back();
        //while(!con.empty())con.pop_back();
    }
    return 0;
}
