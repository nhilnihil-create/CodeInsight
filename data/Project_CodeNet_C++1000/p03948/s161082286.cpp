#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#define LL long long
#define range(tmp,a,b) for(int tmp=a;tmp<=b;++tmp)
#define rerange(tmp,a,b) for(int tmp=a;tmp>=b;--tmp)
#define CLS(array) memset(array,0,sizeof(array))
using namespace std;
int n,t,MIN,MAX,ans;
vector<int>A;
void init(){
    cin>>n>>t;
    range(i,1,n){
        int tmp;
        cin>>tmp;
        A.push_back(tmp);
    }
    ans=1;
}
void solve(){
    MIN=A[0];MAX=0;
    range(i,1,n-1){
        ans+=(MAX==A[i]-MIN?1:0);
        if(A[i]-MIN>MAX){
            MAX=A[i]-MIN;
            ans=1;
        }
        MIN=min(MIN,A[i]);
    }
    cout<<ans<<endl;
}
int main(int argc, char *argv[]) {
    init();
    solve();
    return 0;
}