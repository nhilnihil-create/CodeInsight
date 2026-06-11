#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int A,B;
    cin>>A>>B;
    string ans;
    if(A==B){
        ans="Draw";
    }else if(A==1){
        ans="Alice";
    }else if(B==1){
        ans="Bob";
    }else if(A<B){
        ans="Bob";
    }else{
        ans="Alice";
    }
    cout << ans << endl;
    return 0;
}