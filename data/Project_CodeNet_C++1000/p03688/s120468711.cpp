/*
螺旋本 p371

circumcenter:
    https://ja.wikipedia.org/wiki/%E5%A4%96%E6%8E%A5%E5%86%86#%E5%A4%96%E5%BF%83%E3%81%AE%E4%BD%8D%E7%BD%AE
    https://mathtrain.jp/goshin
*/
#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
using namespace std;
#define INF 1LL << 55
#define MAX 1LL << 30
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
//typedef pair<pair<int,int>,int> p;
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());
//#define int ll
int dx[]={1,-1,0,0},dy[]={0,0,-1,1};

signed main(){
    int N;
    cin>>N;

    vector<int> a(N);
    for(int i=0;i<N;i++) cin>>a[i];
    sort(a.begin(),a.end());
    //差が2以上は駄目
    if(a[N-1]-a[0]>=2){
        cout<<"No"<<endl;
        return 0;
    }
    int count0=0,count1=0;
    for(int i=0;i<N;i++){
        if(a[i]==a[0]) count0++;
        else count1++;
    }
    if(count0==N){
        if(a[0]==N-1 || a[0]<=N/2 ){
            cout<<"Yes"<<endl;
        }else cout<<"No"<<endl;
        return 0;
    }
    if(count1<=1){
        cout<<"No"<<endl;
        return 0;
    }
    if(a[N-1]>=count0+1 && a[N-1]<=count0+count1/2){
        cout<<"Yes"<<endl;
    }else cout<<"No"<<endl;

}