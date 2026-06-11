#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
using namespace std;

template<typename T> class segtree {
private:
    int n,sz;
    vector<pair<T, int> > node;
public:
    segtree(vector<T>& v) : sz((int)v.size()){
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.resize(2*n, make_pair(numeric_limits<T>::min(), -1));
        for(int i = 0; i < sz; i++){
            node[i+n] = make_pair(v[i], -i);
        }
        for(int i=n-1; i>=1; i--){
            node[i] = max(node[2*i], node[2*i+1]);
        }
    }
    void update(int k, T a)
    {
    	node[k+n] = make_pair(a, k);
    	k+=n;
        while(k>>=1){
            node[k] = max(node[2*k], node[2*k+1]);
    	}
    }
    pair<T, int> query(int a,int b,int k=0,int l=0,int r=-1)
    {
        pair<T, int> res1 = make_pair(numeric_limits<T>::min(), -1);
        pair<T, int> res2 = make_pair(numeric_limits<T>::min(), -1);
        a += n, b += n;
        while(a != b){
            if(a % 2) cmx(res1, node[a++]);
            if(b % 2) cmx(res2, node[--b]);
            a >>= 1, b>>= 1;
        }
        return max(res1, res2);
    }
    void print()
    {
        for(int i = 0; i < sz; i++){
            pair<T, int> p;
            p = query(i,i+1);
            cout << "st[" << i << "]: " << p.fi << " " << p.se << endl;
        }
    }
};

ll res[100010];
ll sm[100010];

int main(){
    int n;
    cin >> n;
    vector<ll> v(n+1);
    priority_queue<pair<ll,int> > pq;
    rep(i,n){
        ll a;
        cin >> a;
        v[i+1] = a;
        sm[i+1] = 1;
        pq.push(MP(a,-i-1));
    }
    segtree<ll> sg(v);
    int last = -1;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        ll a = x.first;
        int i = -x.second;
        pair<ll,int> ppp = sg.query(0,i);
        ll val = ppp.first;
        int id = -ppp.second;
        
        if(!pq.empty()){
            auto y = pq.top();
            pq.pop();
            ll b = y.first;
            int j = -y.second;
            if(i<j){
                res[i] += (b-val)*sm[j];
                sm[id] += sm[j];
                pq.push(MP(a,-i));
            }else{
                res[i] += (a-b)*sm[i];
                sm[j] += sm[i];
                pq.push(MP(b,-j));
            }
        }else{
            res[i] += a*sm[i];
        }
    }
    rep(i,n){
        cout << res[i+1] << endl;
    }
    return 0;
}