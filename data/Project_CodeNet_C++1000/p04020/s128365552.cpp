#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N;
    cin >> N;
    ll a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    ll ans=0;
    ll res=0;
    for(int i=0;i<N;i++){
        if(a[i]==0){
            ans+=res/2;
            res=0;
        }else{
            res+=a[i];
        }
    }
    ans+=res/2;
    cout << ans << endl;
}