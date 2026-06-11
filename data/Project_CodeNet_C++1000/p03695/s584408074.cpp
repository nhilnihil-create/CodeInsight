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
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,ex=0;
    cin>>n;
    vector<int>v;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    set<pair<int,int> >s;
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++)
    {
        if(v[i]>=1 && v[i]<=399)
        {
            s.insert({1,399});
        }
        if(v[i]>=400 && v[i]<=799)
        {
            s.insert({400,799});
        }
        if(v[i]>=800 && v[i]<=1199)
        {
            s.insert({800,1199});
        }
        if(v[i]>=1200 && v[i]<=1599)
        {
            s.insert({1200,1599});
        }
        if(v[i]>=1600 && v[i]<=1999)
        {
            s.insert({1600,1999});
        }
        if(v[i]>=2000 && v[i]<=2399)
        {
            s.insert({2000,2399});
        }
        if(v[i]>=2400 && v[i]<=2799)
        {
            s.insert({2400,2799});
        }
        if(v[i]>=2800 && v[i]<=3199)
        {
            s.insert({2800,3199});
        }
        if(v[i]>=3200)
            ex++;
    }
    int mn,mx;
    mn=s.size();
    mx=s.size();
    if(mn==0)
        mn=1;
    mx+=ex;
        cout<<mn<<" " <<mx<<endl;


    return 0;
}
