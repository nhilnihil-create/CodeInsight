//おまじない
#include <iostream>
#include<iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn=100000;

ll n;
priority_queue<ll> l,r;
vector<ll>rarr,larr;
ll lsum=0,rsum=0;
ll num[3*maxn];
ll ans;

int main(){
    
    cin >> n;
    rep(i,3*n){
        cin >> num[i];
    }
    
    rep(i,2*n){
        if(l.size()<n){
            l.push(-num[i]);
            lsum-=num[i];
        }else{
            if(-num[i]<l.top()){
                lsum = lsum - l.top()-num[i];
                l.pop();
                l.push(-num[i]);
            }
        }
        if(l.size()==n)larr.push_back(-lsum);
    }
    
    reverse(num,num+3*n);
    
    rep(i,2*n){
        if(r.size()<n){
            r.push(num[i]);
            rsum += num[i];
        }else{
            if(num[i]<r.top()){
                rsum = rsum-r.top()+num[i];
                r.pop();
                r.push(num[i]);
            }
        }
        if(r.size()==n)rarr.push_back(rsum);
    }
    
    rep(i,rarr.size()){
        //cout << larr[i]<<' '<<rarr[rarr.size()-1-i]<<endl;
        if(i==0)ans=larr[i]-rarr[rarr.size()-1-i];
        else ans = max(ans,larr[i]-rarr[rarr.size()-1-i]);
    }
    
    cout << ans<<endl;
    
    return 0;
}
