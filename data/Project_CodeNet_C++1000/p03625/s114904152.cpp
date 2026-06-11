#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    vector<int> va(n);
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        va[i]=a;
    }

    sort(va.begin(),va.end(),greater<>());
    int last=-1;
    int cnt=0;
    vector<ll> memo;
    for(int i=0;i<n;i++){
        
        if(last!=va[i]){
            last=va[i];
            cnt=1;
            continue;
        }else{
            cnt++;
        }
        if(cnt>=2){
            memo.push_back(va[i]);
            cnt-=2;
        }
        if(memo.size()==2) break;
    }
    if(memo.size()>=2){
        cout<<memo[0]*memo[1]<<endl;
    }else{
        cout<<0<<endl;
    }
    
    return 0;
}