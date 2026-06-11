#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 998244353
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 100002
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    FASTIO
    ll n,l,d1,d2;
    cin>>n;
    l=sqrt(n)+1;
    for(int i=l;i>0;i--){
        if(n%i==0){
           d1=log10(i)+1;
           d2=log10(n/i)+1;
           cout<<max(d1,d2)<<endl;
           return 0;
        }
    }
    return 0;
}
