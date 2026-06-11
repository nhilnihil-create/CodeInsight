#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    long A,B;
    string op;
    cin>>A>>op>>B;
    if(op=="+"){
        cout << A+B <<endl;
        return 0;
    }else{
        cout << A-B<<endl;
    }
    return 0;
}