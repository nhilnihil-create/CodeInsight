#include<bits/stdc++.h>

#define fi first
#define se second
#define show(x) cerr << #x << "=" << "\n"
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

class union_find{
public:
    explicit union_find(int _n):n(_n){
        par.resize(static_cast<unsigned long>(_n));
        rank.resize(static_cast<unsigned long>(_n));
        sizes.resize(static_cast<unsigned long>(_n));
        for(int i=0;i<_n;i++){
            par[i]=i;
            rank[i]=0;
            sizes[i]=1;
        }
    }
    
    //親ノードを見つけます
    int find(int a){
        if(par[a]==a)return a;
        return par[a]=find(par[a]);
    }
    
    //aとbが同じグループかの判定
    bool same(int a,int b){
        return find(a)==find(b);
    }
    
    //aとbを同じグループにします
    void unite(int a,int b){
        link(find(a),find(b));
    }
    
    //aが属するグループの要素数を求めます
    int size(int a){
        return sizes[find(a)];
    }
    
    //全体がどのグループに属しているかがわかります
    void view(){
        for(int i=0;i<n;i++){
            cout<<" par"<<"["<<i<<"]="<<par[i]<<((i==n-1)?"\n":",");
        }
        for(int i=0;i<n;i++){
            cout<<"size"<<"["<<i<<"]="<<sizes[i]<<((i==n-1)?"\n":",");
        }
        cout<<endl;
    }

private:
    void link(int a,int b){
        if(same(a,b))return;
        if(rank[a]>rank[b]){
            par[b]=a;
            sizes[a]+=sizes[b];
            sizes[b]=0;
        }else{
            par[a]=b;
            if(rank[a]==rank[b])rank[b]++;
            sizes[b]+=sizes[a];
            sizes[a]=0;
        }
    }
    int n;
    vector<int> par;
    vector<int> rank;
    vector<int> sizes;
};

int n, k, l;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
#ifdef LOCAL_DEFINE
  FILE *stream1;
  FILE *stream2;
  stream1 = freopen("in.txt", "r", stdin);
  stream2 = freopen("out.txt", "w", stdout);
  if (stream1 == NULL) return 0;
  if (stream2 == NULL) return 0;
#endif
  cin >> n >> k >> l;
  union_find uf1(n);
  for (int i = 0; i < k; i++) {
    int a, b; cin >> a >> b;
    uf1.unite(a - 1, b - 1);
  }
  union_find uf2(n);
  for (int i = 0; i < l; i++) {
    int a, b; cin >> a >> b;
    uf2.unite(a - 1, b - 1);
  }
  vector<pair<int,int> > v;
  for (int i = 0; i < n; i++) {
    v.push_back(make_pair(uf1.find(i), uf2.find(i)));
  }
  // uf1.view();
  // uf2.view();
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    int a = uf1.find(i);
    int b = uf2.find(i);
    cout << upper_bound(v.begin(), v.end(), make_pair(a, b)) - lower_bound(v.begin(), v.end(), make_pair(a, b));
    if (i != n - 1) cout << " ";
  }
  cout << endl;
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
  fclose(stream1);
  fclose(stream2);
#endif
  return 0;
}