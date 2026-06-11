#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
const int mod=1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
#define nepe(v) next_permutation(all(v))
#define F first 
#define S second
#define PB push_back 
#define MP make_pair
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;
using vl=vector<long long>;
using vp =vector<pair<int,int>>;

typedef pair<int,int> P;
string s;
int k;
ll INF = 10000000000000000;


int main(){
    int N;
    string S;
    cin >>N>>S;
    vi ST(N);
    rep(i,N){
        if(S[i]=='(') {
            if(i==0){
                ST[0] =-1;
            }
            ST[i]=ST[i-1]-1; 
        }
        else {
            if(i==0){
                ST[0] =1;
            }
            ST[i]=ST[i-1]+1;
        }
    }
    int end =ST[N-1];
    sort(all(ST));
    int M = max(ST[N-1],0);
    rep(i,M){
        S = "("+S;
    } 
    rep(i,M-end){
        S = S+")";
    }
    cout <<S<<endl;
}