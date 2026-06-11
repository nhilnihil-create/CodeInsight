#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int n,x;cin>>n>>x;
    if(x==1||x==2*n-1)cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        if(n==2){
            REP(i,3)cout<<i+1<<endl;
        }
        else if(x==2){
            REP(i,n-2)cout<<5+i<<endl;
            cout<<3<<endl;
            cout<<2<<endl;
            cout<<1<<endl;
            cout<<4<<endl;
            REP(i,n-3)cout<<n+3+i<<endl;
        }else{
            vector<int> v;
            REP(i,x-3)v.push_back(i+1);
            REP(i,2*n-x-2)v.push_back(x+2+i);
            vector<int> w={x-1,x,x+1,x-2};
            v.insert(v.begin()+n-2,w.begin(),w.end());
            REP(i,2*n-1){
                cout<<v[i]<<endl;
            }
        }
        return 0;
    }
    return 0;
}