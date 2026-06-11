#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstring>
#include<cmath>
#include <numeric>
#include<queue>
#include<climits>
#include<cstdio>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
//#define INF ((LLONG_MAX) / (2))
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
typedef pair<ll,int> LL_IP;
#define INF 1e9+7


ll a[10000001];

int main(){

    ll n;
    cin >> n;
    vector<ll> arr;

    REP(i,1e7+1){
        a[i] = i+1;
    }
    REP(i,1e7){
        a[i+1] += a[i];
    }
    REP(i,n){
        if(a[i] >= n){
            ll tmp = a[i] - n;
            REP(j,i+1){
                if((j+1) != tmp){
                    arr.push_back(j+1);
                }
            }
            break;
        }
    }
    REP(i,arr.size()){
        cout << arr[i] << endl;
    }

    return 0;
}