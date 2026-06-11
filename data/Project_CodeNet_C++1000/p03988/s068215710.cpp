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

int C[110];

signed main(){
    int N;
    cin>>N;
    int maxA=0;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        C[a]++;
        chmax(maxA,a);
    }
    int minA=110;
    for(int i=0;i<=maxA;i++){
        C[max(maxA-i,i)]--;
        if(C[max(maxA-i,i)]<0){
            cout<<"Impossible"<<endl;
            return 0;
        }
        chmin(minA,max(maxA-i,i));
    }
    for(int i=0;i<110;i++){
        if(C[i] && i<=minA){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;



}