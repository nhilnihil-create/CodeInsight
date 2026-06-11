#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define forr(i, b, e)     for (int i = b; i < e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);
#define tam 100056
#define offset 10000000
typedef pair<int,short> par;
const int MOD=1e9+7;
vector<int> val,sum,val2,sum2;
void go(vector<int> &val,int n,string txt,vector<int> &sum)
{
    val.assign(n+1,0);
    sum.assign(n+1,0);
    int ant=0;
    forr(i,0,n)
    {
        if (txt[i]=='A')
            val[i+1]=1;
        else
            val[i+1]=2;
        sum[i+1]=ant+val[i+1];
        //cout<<sum[i+1]<<" ";
        ant=sum[i+1];
    }    
    //cout<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    string txt1,txt2;
    cin>>txt1>>txt2;
    int n,m;
    n=txt1.size();
    m=txt2.size();
    int ant=0;
    go(val,n,txt1,sum);
    go(val2,m,txt2,sum2);
    int q;
    cin>>q;
    int iz2,der2,iz,der;
    while(q--)
    {
        cin>>iz>>der>>iz2>>der2;
        if ((sum[der]-sum[iz-1])%3==(sum2[der2]-sum2[iz2-1])%3)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
// PLUS ULTRA!