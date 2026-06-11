#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    ll a,b;
    cin>>a>>b;
    if(a<=0&&0<=b)cout<<"Zero"<<endl;
    else if(a>0&&b>0)cout<<"Positive"<<endl;
    else if(a<0&&b<0){
        ll d=abs(a-b)+1;
        if(d%2)cout<<"Negative"<<endl;
        else cout<<"Positive"<<endl;
    }
    return 0;
}