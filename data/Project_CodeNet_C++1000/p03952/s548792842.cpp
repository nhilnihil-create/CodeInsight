#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    int n,x;
    cin >> n >> x;
    int m = n*2-1;
    if(x==1||x==m){
        cout << "No" << endl;
    }else{
        
        cout << "Yes" << endl;
        
        vector<int>res(m,-1);
        res[n] = x+1;
        res[n-1] = x;
        res[n-2] = x-1;
        vector<bool> used(m+1);
        used[x-1] = 1;
        used[x] = 1;
        used[x+1] = 1;
        int a = 1;
        for(int i=0;i<m;i++){
            if(res[i]==-1){
                while(used[a]){
                    a++;
                }
                used[a] = 1;
                res[i] = a;
            }
        }
        rep(i,m){
            cout << res[i] << "\n";
        }
    }
    return 0;
}