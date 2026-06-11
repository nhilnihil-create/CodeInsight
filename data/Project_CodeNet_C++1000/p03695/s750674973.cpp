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
    vector<int> a;
    map<int,int> mp;
    rep(i,N){
        int t;
        cin>>t;
        t /=400;
        if(t>=8){
            t=8;
        }
        a.push_back(t);
    }
    rep(i,N){
        if(mp.count(a[i])){
            mp[a[i]]++;
        }else{
            mp[a[i]]=1;
        }
    }
    int base=0;
    for(int i=0;i<=7;i++){
        if(mp[i]>0){
            base++;
        }
    }
    int ansmin=base;
    int ansmax=base;
    
    //最小を求める、base=0ならば答えは1,base!=0ならば答えはbase
    if(ansmin==0){
        ansmin=1;
    }

    //最大を求める、答えはbase+mp[8]
    ansmax+=mp[8];
    cout << ansmin << " " << ansmax << endl;
    return 0;
}