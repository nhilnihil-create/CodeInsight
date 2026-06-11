#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using vvv= vector<vv>;

int main(){
    int n;cin>>n;
    vi list(n);
    int m;cin>>m;
    int a,b;
    rep(i,m){
        cin>>a>>b;
        a--;b--;
        list[a]++;
        list[b]++;
    }
    
    rep(i,n){
        if(list[i]%2){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    
    return 0;
}