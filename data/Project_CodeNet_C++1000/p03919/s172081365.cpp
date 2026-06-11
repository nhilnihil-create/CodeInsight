#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL INF=1e18;
string u="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    int H,W;
    cin >> H >> W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            string s;
            cin >> s;
            if(s=="snuke"){
                cout << u[j] << i+1 << endl;
            }
        }
    }
    return 0;
}