#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    int N ,x;
    cin >> N >> x;
    vector<int> a(N);
    rep(i,N){
        cin >> a.at(i);
    }
    long ans=0;
    rep(i,N-1){
        if(x<a.at(i)+a.at(i+1)&&a.at(i)>x){
            ans+=a.at(i+1);
            a.at(i+1)=0;
            ans+=a.at(i)-x;
            a.at(i)=x;
        }else if(x<a.at(i)+a.at(i+1)&&a.at(i)<=x){
            ans+=a.at(i+1)-(x-a.at(i));
            a.at(i+1)=x-a.at(i);
        }else if(x>=a.at(i)+a.at(i+1)){
            continue;
        }else{

        }
    }
    cout << ans << endl;
    return 0;
}
