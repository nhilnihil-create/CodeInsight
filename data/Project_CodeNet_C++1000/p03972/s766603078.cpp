#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
int main(void){
    ll w,h;
    P p[200000];
    ll c=0,a,b,e=0;
    cin>>w>>h;
    for(int i=0;i<w+h;i++){
        ll x;
        cin>>x;
        p[i]=P(x, i);
    }
    sort(p, p+w+h);
    a=w+1;
    b=h+1;
    for(int i=0;i<w+h&&e<w*h+w+h;i++){
        if(p[i].second<w){
            e+=b;
            a--;
            c+=b*p[i].first;
        }else{
            e+=a;
            b--;
            c+=a*p[i].first;
        }
    }
    cout << c << endl;
    //cout << e << endl;
}
