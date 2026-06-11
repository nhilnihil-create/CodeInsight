#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
bool judge(long a,long b,long h,long w){
    if(a<1) return false;
    if(a+2>h) return false;
    if(b<1) return false;
    if(b+2>w) return false;
    return true;
}
int main(){
    long long h,w,n;
    cin >> h >> w >> n;
    long a[n],b[n];
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    long long ans[10] = {0};
    set<pair<long,long>> st;
    map<pair<long,long>,int> mp;
    rep(i,n){
        rep(j,3){
            rep(k,3){
                if(judge(a[i]-j,b[i]-k,h,w)){
                    mp[make_pair(a[i]-j,b[i]-k)]++;
                    st.insert(make_pair(a[i]-j,b[i]-k));
                }
            }
        }
    }
    ans[0]=(h-2)*(w-2)-st.size();
    for(auto itr = st.begin();itr!=st.end();itr++){
        ans[mp[*itr]]++;
    }
    rep(i,10){
        cout << ans[i] << endl;
    }
}