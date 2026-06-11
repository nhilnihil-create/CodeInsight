#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    string S;
    cin>>S;
    int n = S.size();
    vector<int> dig;
    rep(i,n){
        dig.push_back(S[i]-'0');
    }

    long long ans=0;
    rep(i,n){
        int k=0;
        for(int j=0;j<n-i;j++){
            if(j==n-i-1){
            ans=ans+(pow(10,i)*dig[j]*pow(2,n-1-i));
            }else{
            ans=ans+(pow(10,i)*dig[j]*pow(2,n-2-i));    
            }
//            cout << (pow(10,i)*dig[j]*pow(2,n-2-i)) << endl;
        }
//    cout << i << ":" << endl;
    }
    cout << ans << endl;
    return 0;
}