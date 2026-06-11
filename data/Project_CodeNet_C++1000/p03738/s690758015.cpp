#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define s second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;



void solve()
{
    string n1,n2;
    cin>>n1>>n2;
    if(n1.size()>n2.size()){
        cout<<"GREATER"<<endl;
    }
    else if(n1.size()<n2.size()){
        cout<<"LESS"<<endl;
    }
    else{
        for(ll i=0;i<n1.size();++i){
            if(n1[i]>n2[i]){
                cout<<"GREATER"<<endl;
                return;
            }
            else if(n1[i]<n2[i]){
                cout<<"LESS"<<endl;
                return;
            }
        }
        cout<<"EQUAL"<<endl;
    }
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
