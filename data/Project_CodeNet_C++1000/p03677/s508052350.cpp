#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

#define int long long
 
int ope(int a,int b)
{
    return a + b;
}
 
int l_ope(int node,int lazy)
{
    return node + lazy;
}
 
int l_throw(int lazy)
{
    return lazy / 2;
}
 
int l_add(int l,int r,int x)
{
    return (r - l) * x;
}
 
struct LazySegment
{
    vector<int> node;
    vector<int> lazy;
    int n;
 
 
    int init = 0;
 
    LazySegment(const vector<int>& vec)
    {
        int sz = vec.size();
 
        n = 1;
        while(n < sz) n <<= 1;
 
        node.resize(2 * n - 1,init);
        lazy.resize(2 * n - 1,0);
 
        for(int i = 0;i < sz;i++)
        {
            node[n - 1 + i] = vec[i];
        }
 
        for(int i = n - 2;i >= 0;i--)
        {
            node[i] = ope(node[i * 2 + 1] , node[i * 2 + 2]);
        }
    }
 
    void eval(int k,int l,int r)
    {
        if(lazy[k] != 0)
        {
            node[k] = l_ope(node[k],lazy[k]);
 
            if(r - l > 1)
            {
                lazy[2 * k + 1] += l_throw(lazy[k]);
                lazy[2 * k + 2] += l_throw(lazy[k]);
            }
 
            lazy[k] = 0;
        }
    }
 
    void add_inter(int a,int b,int x,int k = 0,int l = 0,int r = -1)
    {
        if(r < 0) r = n;
 
        eval(k,l,r);
 
        if(b <= l || r <= a) return ;
 
        if(a <= l && r <= b)
        {
            lazy[k] += l_add(l,r,x);
            eval(k,l,r);
        }
 
        else
        {
            add_inter(a,b,x,2 * k + 1,l,(l + r) / 2);
            add_inter(a,b,x,2 * k + 2,(l + r) / 2,r);
            node[k] = ope(node[2 * k + 1], node[2 * k + 2]);
        }
    }
 
    int get_inter(int a,int b,int k = 0,int l = 0,int r = -1)
    {
        if(r < 0) r = n;
 
        eval(k,l,r);
        if(b <= l || r <= a) return init;
 
        if(a <= l && r <= b) return node[k];
 
        int lv = get_inter(a,b,k * 2 + 1,l , (l + r) / 2);
        int rv = get_inter(a,b,k * 2 + 2,(l + r) / 2 , r);
 
        return ope(lv , rv);
    }
};
 

int N,M;
vector<int> a;

signed main(){
  cin >> N >> M;
  a.resize(N);
  rep(i,0,N - 1){
    cin >> a[i];
    a[i]--;
  }

  LazySegment seg(vector<int>(3 * M + 10,0));

  i64 sum = 0;

  rep(i,0,N - 2){
    if(a[i] < a[i + 1]){
      sum += a[i + 1] - a[i];
      seg.add_inter(a[i] + 2,a[i + 1] + 1,1);
      seg.add_inter(a[i] + 2 + M , a[i + 1] + M + 1,1);
      int sz = a[i + 1] - a[i] - 1;
      seg.add_inter(a[i + 1] + 1,a[i + 1] + 2,-sz);
      seg.add_inter(a[i + 1] + 1 + M,a[i + 1] + 2 + M,-sz);

    }
    else{
      sum += a[i + 1] + M - a[i];
      seg.add_inter(a[i] + 2 , a[i + 1] + M + 1,1);
      seg.add_inter(a[i] + 2 + M,a[i + 1] + M + M + 1,1);
      int sz = a[i + 1] + M - a[i] - 1;
      seg.add_inter(a[i + 1] + M + 1,a[i + 1] + M + 2,-sz);
      seg.add_inter(a[i + 1] + M + 1 + M,a[i + 1] + M + 2 + M,-sz);

    }
  }


  i64 MAX = 0;
  rep(i,0,M * 3){
    MAX = max(MAX,seg.get_inter(0,i + 1));

  }

  cout << sum - MAX << endl;
}
