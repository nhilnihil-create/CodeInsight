/*
貪欲
後ろから見る
DP
順位表をチェック
二分探索
不変なもの・偶奇に注目

*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
#include<tuple>
#include<set>
using namespace std;
#define INF 1LL<<60
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,bool> P;
//typedef pair< pair<int,int>,pair<int,int> > p;
//#define int ll int main->signed main
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());

//https://www.hamayanhamayan.com/entry/2017/07/23/233641

int N,M;
int A[310][310];

int check(int x){
    vector< queue<int> > vq(N);
    vector<int> used(M,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) vq[i].push(A[i][j]);
    }

    while(true){
        map<int,int> M;
        for(int i=0;i<N;i++){
            M[vq[i].front()]++;
        }
        vector<int> ng;
        for(auto p:M){
            if(x<p.second) ng.push_back(p.first);
        }
        if(ng.size()==0) return 1;
        for(auto j:ng){
            used[j]=1;
        }

        for(int i=0;i<N;i++){
            while(!vq[i].empty() && used[vq[i].front()]) vq[i].pop();
            if(vq[i].empty()) return 0;
        }
    }

}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
            A[i][j]--;
        }
    }
    int ng=0,ok=N;
    while(ng+1!=ok){
        int x=(ng+ok)/2;
        if(check(x)) ok=x;
        else ng=x;
    }
    cout<<ok<<endl;
}
