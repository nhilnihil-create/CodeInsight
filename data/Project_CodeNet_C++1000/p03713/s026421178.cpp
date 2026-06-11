#include <iostream>
#include<iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <queue>
#define INF 1e16
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout<< "YES"<<endl;
#define No cout<< "No"<<endl;
#define Yes cout<< "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define space ' '
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//(int)'a'=97 (int)'A'=65 (int)'1'=49
//おまじない

const int maxn = 100000;

int main(){
    
    ll w,h;
    cin >> h>>w;
    ll ans = INF;
    for(ll i=1;i<=w-1;i++){
        ll w1 = i;
        ll w2 = (w-i)/2;
        ll w3 = w-(w1+w2);
        ll h1 = h/2;
        ll h2 = h-h1;
        if(i<=w-2)ans=min(ans,(max(max(w1,w2),w3)-min(min(w1,w2),w3))*h);
        ans=min(ans,max(max(i*h,h1*(w-i)),h2*(w-i))-min(min(i*h,h1*(w-i)),h2*(w-i)));
    }
    swap(w,h);
    
    for(ll i=1;i<=w-2;i++){
        ll w1 = i;
        ll w2 = (w-i)/2;
        ll w3 = w-(w1+w2);
        ll h1 = h/2;
        ll h2 = h-h1;
        if(i<=w-2)ans=min(ans,(max(max(w1,w2),w3)-min(min(w1,w2),w3))*h);
        ans=min(ans,max(max(i*h,h1*(w-i)),h2*(w-i))-min(min(i*h,h1*(w-i)),h2*(w-i)));
    }
    
    cout << ans<<endl;
    
    return 0;
}
