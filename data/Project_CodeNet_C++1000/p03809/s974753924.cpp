#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

bool flag = 0;

ll saiki(int x,vector<ll> &a,vector<set<int> > &st){
    if(flag)return -1;    
    if(st[x].size()==0){
        return a[x];
    }
    ll tmp = 0;
    ll mx = 0;
    for(auto k:st[x]){
        st[k].erase(x);
        ll z = saiki(k,a,st);
        mx = max(mx,z);
        tmp += z;
    }
    ll ans = 2*a[x]-tmp;
    ll k = a[x]-ans;
    if(k>tmp-mx||k>tmp/2){
        flag = 1;
        return -1;
    }
    if(ans<0||ans>tmp){
        flag = 1;
        return -1;
    }else{
        return ans;
    }
}



int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<set<int> > st(n);
    rep(i,n-1){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        st[x].insert(y);
        st[y].insert(x);
    }
    if(n==2){
        if(a[0]==a[1]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        return 0;
    }
    int x = 0;
    if(st[x].size()==1){
        x = *st[x].begin();
    }
    ll p = saiki(x,a,st);
    if(flag||p!=0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}