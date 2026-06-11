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
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    map<int,int>mp;
    vector<int>v;
    int n;
    cin>>n;
    set<int>s;
    while(n--){
        int a;
        cin>>a;
        mp[a]++;
        s.insert(a);
    }
    for(auto i:s){
        while(mp[i]>1)
        {
            v.push_back(i);
            mp[i]-=2;
        }
    }
    sort(v.begin(),v.end());
    if(v.size()<2)
        cout<<"0"<<endl;
    else{
        ll x=v[v.size()-1];
        ll y=v[v.size()-2];
        cout<<x*y<<endl;
    }
    return 0;
}
