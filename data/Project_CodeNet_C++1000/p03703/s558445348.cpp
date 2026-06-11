#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,int> pi;
typedef tuple<int,int,int> piii;
const int INF=10000000;
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define all(x) (x).begin(), (x).end()


const int N = 1000000;  
  
int n,m,k; // array size 
  
// Max size of tree 
ll tree[2 * N]; 
  
// function to build the tree 
void build( ll arr[])  {  
    // insert leaf nodes in tree 
    for (int i=0; i<n; i++)     
        tree[n+i] = arr[i]; 
      
    // build the tree by calculating parents 
    for (int i = n - 1; i > 0; --i)      
        tree[i] = tree[i<<1] + tree[i<<1 | 1];     
} 
  
// function to update a tree node 
void updateTreeNode(int p, int value) {  
    // set value at position p 
    tree[p+n] = value; 
    p = p+n; 
      
    // move upward and update parents 
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
} 
  
// function to get sum on interval [l, r) 
int query(int l, int r) {  
    int res = 0; 
      
    // loop to find the sum in the range 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res += tree[l++]; 
      
        if (r&1)  
            res += tree[--r]; 
    } 
      
    return res; 
} 
  

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> m >> k;
  vector<ll> temp(m+1);
  vector<ll> x(m);
  vector<ll> rs(m+1);

  for (int i=0; i<m; i++){
    cin >> x[i];
    x[i]-=k;
  }

  for (int i=0; i<m; i++){
    rs[i+1]=rs[i]+x[i];
    temp[i+1]=temp[i]+x[i];
  }


  // for(ll i: temp) cout<<i<<" ";
  // cout<<endl; 

  sort(temp.begin(),temp.end());

  // for (ll i: temp) cout<<i<<" ";
  // cout<<endl; 

  map<ll,int> pointer;
  int idx=0;
  for (ll i: temp){
    if (pointer.find(i)==pointer.end()){
      pointer[i]=idx;
      idx++;
    }
  }




  ll a[idx+1];
  ll b[idx+1];
  for (int i=0; i<idx+1; i++){
    a[i]=0;
    b[i]=0;
  }



  build(a);
  n=sizeof(a)/sizeof(a[0]);



  ll ans=0;
  for (ll i: rs){
    int index=pointer[i];
    ans+=query(0,index+1);
    //cout<<i<<" "<<ans<<endl;
    
    updateTreeNode(index,b[index]+1);
    b[index]++;



  }

  cout<<ans<<endl;


  






} 
