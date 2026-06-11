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
    vector<int> s;
    vector<int> s1;
    int ans=0;
    rep(i,N){
        int t;
        cin>>t;
        s.push_back(t);
        ans+=t;
        if(t%10!=0){
            s1.push_back(t);
        }
    }
    if(ans%10!=0){
        cout << ans << endl;
        return 0;
    }
    if(s1.size()==0){
        cout << 0 << endl;
        return 0;
    }

    sort(all(s1));
    ans-=s1.at(0);
    cout << ans << endl;


    return 0;
}