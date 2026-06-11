#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int N;
    cin>>N;
    long long P=1000000007LL;
    long long ans=1;
    //素数をキーにかかってる個数をmap
    map<int,int> primes;
    set<int> prime;
    rep2(i,2,N+1){
    int tmp=i;
        rep2(j,2,i+1){
            if(tmp%j==0){
                while(tmp%j==0){
                    prime.insert(j);
                    tmp=tmp/j;
                    if(primes.count(j)){
                        primes[j]++;
                    }else{
                        primes[j]=1;
                    }
                }
            }else{
                continue;
            }
        }
    }
    // cout << primes.size() << endl;    
    rep(i,1000){
        if(primes.count(i)){
            ans=(ans*(primes[i]+1))%P;
        }else{
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}