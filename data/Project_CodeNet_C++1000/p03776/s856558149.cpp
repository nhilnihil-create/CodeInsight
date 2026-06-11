#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,a,b;
    cin>>n>>a>>b;
    double c;
    multiset<double> ms;
    multiset<double>::iterator itr;
    for(int i=0;i<n;i++){
        cin>>c;
        ms.insert(c);
    }
    double num=0;
    itr=ms.end();
    for(int i=0;i<a;i++){
        itr--;
        num+=*itr;
    }
    num/=a;
    doublecout(num);
    num=*itr;
    itr=ms.end();
    ll x=0,y=0;
    bool maki=false;
    for(int i=0;i<n;i++){
        itr--;
        if(*itr!=num){
            if(maki)break;
            else x++;
        }
        else{
            y++;
            maki=true;
        }
    }

    ll com[51];
    com[0]=1;
    for(ll i=1;i<=y;i++){
        com[i]=com[i-1]*(y-i+1)/i;
    }

    if(x==0){
        n=0;
        for(ll i=a;i<=min(b,y);i++){
            n+=com[i];
        }
        cout << n<<endl;
    }
    else{
        cout<<com[a-x]<<endl;
    }
    return 0;
}


