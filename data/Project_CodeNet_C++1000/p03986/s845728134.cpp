#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string X;
    cin >> X;
    int cnt = 0;
    int cnt2 = 0;
    for(int i=0;i<X.size();i++){
        cnt2++;
        if(X[i]=='S'){
            cnt++;
        }else{
            // S→Tの場合
            if(cnt){
                cnt--;
                cnt2-=2; // SとT分を消す
            }
        }
    }
    cout << cnt2 << endl;
    return 0;
}