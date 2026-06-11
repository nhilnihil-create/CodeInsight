#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const double INF = 1e9;
 
ll a,b,c,d,e,f;
 
int main(){
    cin >> a >> b >> c >> d >> e >> f;
    //step1
    vector<bool>water(3010,false);
    for(int i=0;i*100*a<=f;i++){
        for(int j=0;j*100*b<=f;j++){
            if(i*100+j*100>f)continue;
            water[i*a*100+j*b*100]=true;
        }
    }
    vector<bool>sugar(3010,false);
    for(int i=0;i*c<=f;i++){
        for(int j=0;j*d<=f;j++){
            if(i*c+j*d>f)continue;
            sugar[i*c+j*d]=true;
        }
    }
 
    //step2
    double M = -1;
    P ans = {-1,-1};
    for(int i=1;i<=f;i++){
        for(int j=0;j<=f;j++){
            if(!water[i])continue;
            if(!sugar[j])continue;
            if(i+j>f)continue;
            if((100+e)*(100*j)>100*e*(i+j))continue;
            double now = 100.0*j;
            now = now/(i+j);
            if(chmax(M,now)){
                ans.first=i+j;
                ans.second=j;
            }
        }
    }
    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}