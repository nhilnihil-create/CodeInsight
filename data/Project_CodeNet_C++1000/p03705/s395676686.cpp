/*    Mohammed Sami Khan
                       মোহাম্মদ সামী খান
*/
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define endl "\n"
#define mp(a,b) make_pair(a,b)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
typedef unsigned long long ull;

bool sortbysecc(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

int main()
{
    fastio;
    ll t, n, a, b, m, p, q, r, i, j, d, f=0;
    char *ye="POSSIBLE", *no="IMPOSSIBLE";
    cin>>n>>a>>b;
    if(a>b){
        cout<<0<<endl;
    }
    else if(a!=b&&n==1) cout<<0<<endl;
    else if(a==b){
        cout<<1<<endl;
    }
    else{
        q=a+b+(n-2)*b;
        p=a+b+(n-2)*a;
        cout<<q-p+1<<endl;
    }
}
