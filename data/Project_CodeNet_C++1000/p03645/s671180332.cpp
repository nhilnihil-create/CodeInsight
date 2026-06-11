#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
#define ll long long
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> cntships(N,0);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        if(a==1||a==N){
            cntships[b-1]++;
        }else if(b==1||b==N){
            cntships[a-1]++;
        }
        if(cntships[a-1]==2||cntships[b-1]==2){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}