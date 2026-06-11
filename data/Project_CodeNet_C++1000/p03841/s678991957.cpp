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
#include <iomanip>
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
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
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
    int n;
    cin >> n;
    vector<int>a(n*n);
    vector<pair<int,int> >b;
    rep(i,n){
        int k;
        cin >> k;
        b.push_back(MP(k-1,i+1));
    }
    sort(b.begin(),b.end());
    int id = 0;
    queue<int> q;
    bool ng = 0;
    rep(i,n){
        int c = b[i].second;
        int xid = b[i].first;
        if(a[xid]!=0){
            ng = 1;
            break;
        }
        a[xid] = c;
        rep(k,c-1){
            while(a[id]!=0)id++;
            if(id>=xid)ng = 1;
            a[id] = c;
        }
        rep(k,n-c){
            q.push(c);
        }
    }
    if(ng){
        cout << "No\n";
        return 0;
    }
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        while(a[id]!=0){
            id++;
        }
        a[id] = x;
    }
    vector<int> res(n+1);
    vector<int> cnt(n+1);
    rep(i,n*n){
        cnt[a[i]]++;
        if(cnt[a[i]] == a[i]){
            res[a[i]] = i;
        }
    }
    for(auto x:b){
        if(res[x.second]!=x.first){
            ng = 1;
        }
    }
    if(ng){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    rep(i,n*n){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}