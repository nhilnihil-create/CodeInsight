#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    ll r;
    while(a%b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}
int main(){
    ll N,K;
    cin >> N >> K;
    ll A;
    cin >> A;
    ll l=A,m=A;
    ll i;
    for(i=0;i<N-1;i++){
        cin >> A;
        l=gcd(l,A);
        m=max(m,A);
    }
    if(K<=m&&K%l==0)cout << "POSSIBLE"<<endl;else cout << "IMPOSSIBLE";
    return 0;
}
