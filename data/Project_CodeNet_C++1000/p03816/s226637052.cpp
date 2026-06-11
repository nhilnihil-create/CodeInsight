#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N){
        cin>>A[i];
    }
    map<int,int> cnt;
    rep(i,N){
        if(cnt.count(A[i])){
            cnt[A[i]]++;
        }else{
            cnt[A[i]]=1;
        }
    }

    int oc=0;
    int tc=0;
    rep(i,100001){
    //同じカードが3枚以上なら2ずつ減らせる
        if(cnt[i]==0){
            continue;
        }else{
            if(cnt[i]>=3){
                cnt[i]= (cnt[i]%2==0) ? 2 : 1;
            }
            if(cnt[i]==1){
                oc++;
            }else{
                tc++;
            }
        }
    }
    //2の数は偶数個1にできる
    int ans=0;
    // cout <<cnt[4]<<endl;
    ans=(tc%2==0)?oc+tc:oc+tc-1;
    cout << ans << endl;

    return 0;
}