#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Possible");}else{puts("Impossible");}

int main() {
    int n;
    cin >> n;
    int count[101] = {};
    int ma = 0;
    int flag = 0;
    rep(i,n){
        int a; cin >> a;
        count[a]++;
        ma = max(ma,a);
    }

    if(count[ma]<2){
        flag = 1;
    }

    if(ma%2==0){
        srep(i,1,ma+1){
            if(i<ma/2){
                if(count[i]!=0)flag=1;
            }else if(i==ma/2){
                if(count[i]!=1)flag=1;
            }else{
                if(count[i]<2)flag=1;
            }
        }
    }else{
        srep(i,1,ma+1){
            if(i<=ma/2){
                if(count[i]!=0)flag=1;
            }else if(i==(ma+1)/2){
                if(count[i]!=2)flag=1;
            }else{
                if(count[i]<2)flag=1;
            }
        }
    }

    if(flag==0)yn;

    return 0;
}
 
 
