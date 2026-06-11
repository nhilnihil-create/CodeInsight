#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 2e5 + 5;

int n , a[maxn] , m;
ll s[maxn * 4] , lz[maxn * 4];
ll cnt[maxn * 4];
ll ans[maxn];

void Push(int x , int l , int r){
//    cout << l << " " << r << " " << x << " " << cnt[x] << " " << lz[x] << endl;
    if(l == r)return;
    lz[x * 2] += lz[x];
    lz[x * 2 + 1] += lz[x] + ((l + r) / 2 - l + 1) * cnt[x];
    cnt[x * 2] += cnt[x];
    cnt[x * 2 + 1] += cnt[x];
    lz[x] = cnt[x] = 0;
}

void update(int x , int l , int r , int L , int R , int delta){
//    Push(x , l , r);
//    cout << x << " " << l << " " << r << " " << L << " " << R << " " << delta << endl;
    if(L > r || l > R)return ;
    if(L <= l && r <= R){
        lz[x] += delta + l - L;
        cnt[x]++;
        return;
    }
    int mid = l + r >> 1;
    update(x * 2 , l , mid , L , R , delta);
    update(x * 2 + 1 , mid + 1 , r , L , R , delta);
}

void Build(int x , int l , int r){
    Push(x , l , r);
    if(l == r){
        ans[l] = lz[x];
        return;
    }
    int mid = l + r >> 1;
    Build(x * 2 , l , mid);
    Build(x * 2 + 1 , mid + 1 , r);
}

int main(){
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)cin >> a[i];
    ll res = 0;
    for(int i = 1 ; i < n ; ++i){
        if(a[i] <= a[i + 1]){
            update(1 ,1,m,a[i]+1,a[i+1],0);
//            cout << a[i] + 1 << " " << a[i + 1] << " " << 0 << endl;
            res += a[i + 1] - a[i];
        }else{
            update(1 , 1 , m , a[i]+1,m,0);
            update(1 , 1 , m , 1,a[i + 1],m - a[i]);
//            cout << a[i] + 1 << " " << m << " " << 0 << endl;
//            cout << 1 << " " << a[i + 1] << " " << m - a[i] << endl;
            res += m - a[i] + a[i + 1];
        }
    }
    Build(1,1,m);
    cout << res - *max_element(ans+1,ans+m+1);
}
