#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    int h,w;
    cin>>h>>w;
    vector<vector<string >> s(h,vector<string>(w));
    for(auto& e:s){
        for(auto& c:e){
            cin>>c;
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j]=="snuke"){
                cout<<char('A'+j)<<i+1<<endl;
                return;
            }
        }
    }
}

signed main(){
    //while(1)
    solve();
}