#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l,T r)
{bool a=l>r;if(a)l=r;return a;}
template <typename T>inline bool chmax(T &l,T r)
{bool a=l<r;if(a)l=r;return a;}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
vector<int> res;
int num=1;
void f(LL n){
    if(n<=0)
        return;    
    f((n-1)/2);
    res.push_back(num++);
    if(n&1);
    else res.insert(res.begin(),num++);
}
int main(){
    LL N;
    cin>>N;
    f(N);
    cout<<res.size()*2<<endl<<1;
    FOR(i,2,num)cout<<" "<<i;
    for(auto &it:res)cout<<" "<<it;
    cout<<endl;
    
    return 0;
}
