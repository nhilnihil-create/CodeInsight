#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef pair<int,int> p;
int n,k,l;
int a[200001];
int b[200001];
map <p,int> m;

void init(int n) {
  for(int i = 0; i < n; i++) {
    a[i] = i;
    b[i] = i;
  }
}

int Find(int x,bool ok) {
  if(ok) return a[x] == x ? x : a[x] = Find(a[x],ok);
  else return b[x] == x ? x : b[x] = Find(b[x],ok);
}

void Union(int x, int y, bool ok) {
  x = Find(x,ok);
  y = Find(y,ok);
  if(ok) {
    if(Find(x,ok) == Find(y,ok)) return;
    a[x] = y;
  }
  else {
    if(Find(b[x],ok) == Find(b[y],ok)) return;
    b[x] = y;
  }
}
  
  
int main() {
  cin >> n >> k >> l;
    init(n);
  for(int i = 0; i < k; i++) {
    int p,q;
       cin >> p >> q;
     p--; q--;
    Union(p,q,true);
  }


  
  for(int i = 0; i < l; i++) {
    int r,s;
       cin >> r >> s;
     r--; s--;
    Union(r,s,false);
  }

 
  for(int i = 0; i < n; i++) {
    m[mp(Find(i,true),Find(i,false))]++;
   }

  for(int i = 0; i < n; i++) {
    cout << m[mp(Find(i,true),Find(i,false))] <<endl;
  }
}
  
  
