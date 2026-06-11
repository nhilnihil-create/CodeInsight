#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    deque<int> v;
    rep(i,n){
        int a;
        cin>>a;
        if(i%2==0) v.push_back(a);
        else v.push_front(a);
    }

    if(n%2==1) reverse(all(v));
    while(!v.empty()){
        cout<<v.front()<<" ";
        v.pop_front();
    }

    cout<<endl;
}
