#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=998244353;
const LL LINF=1LL<<60;
const int INF=1<<30;





int main(){
    int H,W,h,w;cin >> H >> W >> h >> w;
    if(H%h==0&&W%w==0){
        puts("No");
        return 0;
    }
    puts("Yes");
    if(W%w==0){
        vector<int> s(H+1,501);
        s[0] = 0;
        for (int i = 0; i <= H; i++) {
            if(i+h<=H) s[i+h] = s[i] - 1;
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                cout << s[i] - s[i-1] << (j==W?"\n":" ");
            }
        }
    }
    else{
        vector<int> s(W+1,501);
        s[0] = 0;
        for (int i = 0; i <= W; i++) {
            if(i+w<=W) s[i+w] = s[i] - 1;
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                cout << s[j] - s[j-1] << (j==W?"\n":" ");
            }
        }
    }
    return 0;
}
