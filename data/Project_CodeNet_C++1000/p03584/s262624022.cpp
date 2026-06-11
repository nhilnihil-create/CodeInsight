#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
int N,K,A[100010];
ll B[100010] = {};

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> A[i] >> B[i];        
    }
    int value = 0;
    ll ans = 0;
    set<int> s;
    for(int j=0;j<=30;j++){
        if(!(K&(1<<j))) s.insert(j);
    }
    for(int i=1;i<=N;i++){
        bool judge = true;
        for(auto x:s){
            if(A[i]&(1<<x)){
                judge = false;
                break;
            }
        }
        if(judge) ans += B[i];
    }
    for(int j=0;j<=30;j++){
        if(K<(1<<j)) break;
        if(K&(1<<j)){
            ll now = 0;
            if(j!=0) s.insert(j);
            for(int i=1;i<=N;i++){
                bool judge = true;
                for(auto x:s){
                    if(A[i]&(1<<x)){
                        judge = false;
                        break;
                    }
                }
                if(judge) now += B[i];
            }
            ans = max(ans,now);
            if(j!=0) s.erase(j);
        }else s.erase(j);
    }
    cout << ans << endl;
}
