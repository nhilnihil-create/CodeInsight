#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
const long long MOD=1000000007LL;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    long long ans=1;
    //Nが奇数⇒0が一個と偶数が2個ずつ出てくればOK、その時2^(N/2)が答え
    //Nが偶数⇒奇数が2個ずつ出てくればOK、その時2^(N/2)が答え
    rep(i,N){
        cin>>A.at(i);
    }
    rep(i,N/2){
        ans=(ans*2)%MOD;
    }
    sort(all(A));
    if(N%2==0){
        rep(i,N){
            if(i%2==0){
                if(A.at(i)!=i+1){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(A.at(i)!=i){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }else{
        rep(i,N){
            if(i%2==0){
                if(A.at(i)!=i){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(A.at(i)!=i+1){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }        
    }
    cout << ans << endl;
    return 0;
}