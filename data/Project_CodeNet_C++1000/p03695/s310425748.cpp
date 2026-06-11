#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    int rain=0;
    set<int> s;
    rep(i,n){
        int a;cin>>a;
        if(a<400)s.insert(0);
        else if(a<800)s.insert(1);
        else if(a<1200)s.insert(2);
        else if(a<1600)s.insert(3);
        else if(a<2000)s.insert(4);
        else if(a<2400)s.insert(5);
        else if(a<2800)s.insert(6);
        else if(a<3200)s.insert(7);
        else rain++;
    }
    int res1=max(1,(int)(s.size()));
    cout<<res1<<" ";
    int resm=s.size()+rain;
    cout<<resm<<endl;
}
