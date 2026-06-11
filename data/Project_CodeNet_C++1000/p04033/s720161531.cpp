#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll a,b;cin>>a>>b;
    if((a>0&&b>0)||(b-a)%2!=0){
        cout<<"Positive"<<endl;
        return 0;
    }else if(a<=0&&b>=0){
        cout<<"Zero"<<endl;
        return 0;
    }else{
        cout<<"Negative"<<endl;
        return 0;
    }
}