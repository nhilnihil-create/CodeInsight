#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;

int main(){
    map<pair<int,int>, int> mp;
    ll H,W,N;
    ll ANS[10];
    cin>>H>>W>>N;
    ANS[0]=(H-2)*(W-2);
    for(int i = 1;i <= 9;i++){
        ANS[i]=0;
    }
    ll a_,b_;
    for(int i = 0;i < N;i++){
        cin>>a_>>b_;
        a_--;b_--;
        for(ll a = min(a_,H-3);a_-a < 3&&a>=0;a--){
            for(ll b = min(b_,W-3);b_-b < 3&&b>=0;b--){
                //cout<<a<<b<<endl;
                if(mp.count(make_pair(a,b))==0){
                    mp[make_pair(a,b)]=1;
                }else{
                    mp[make_pair(a,b)]++;
                }
            }
        }
    }
    map<pair<int,int>,int>::iterator it = mp.begin();
    while(it!=mp.end()){
        ANS[it->second]++;
        ANS[0]--;
        it++;
    }
    for(int i = 0;i <= 9;i++){
        cout<<ANS[i]<<endl;
    }
}
