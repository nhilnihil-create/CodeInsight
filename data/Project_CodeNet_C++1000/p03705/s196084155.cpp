# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
ll n,a,b,x,y;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>a>>b;
    if(a>b){
        cout<<0<<endl;
        return 0;
    }
    if(a==b){
        cout<<1<<endl;
        return 0;
    }

    if(n==1){
        if(a!=b) cout<<0<<endl;
        else cout<<1<<endl;
        return 0;
    }
    x=(n-2)*b;
    y=(n-2)*a;
    cout<<x-y+1<<endl;
}