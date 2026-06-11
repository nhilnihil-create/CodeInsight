#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for( int i=a; i<b; i++ )
#define REP(i,n) rep(i,0,n)
#define INF 1000000
using lli = long long int;
using ulli = unsigned long long int;
typedef pair<int, int> P;

struct edge{ int u, v; lli cost; };
struct DirectedGraph
{
  int vertex_num;
  int edge_num;
  vector<edge> edge_list;
  vector< vector<int> > adj_list;
	vector< vector<lli> > distance_matrix;
};


template <typename T>
vector<int> argsort(const vector<T> &v) {

  // initialize original index locations
  vector<int> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](int i1, int i2) {return v[i1] < v[i2];});

  return idx;
}

template<typename T>
void displayVector(vector<T> v)
{
	lli n = v.size();
	REP(i,n){
		cout << v[i] << " " ;
	}
	cout << endl;
}

int count_comb(int a, int b, int c){
  if(a!=b && b!=c){ return 6; }
  else if( a==b && b==c){ return 1; }
  else{ return 3; }
}

string sub(string str, int start, int end){
  // require : start < end
  return str.substr(start, end-start+1);
}

struct C{ int a; int b; };

int main(){
  lli n, k; cin >> n >> k;
  vector<C> vec(n);
  REP(i, n){ cin >> vec[i].a >> vec[i].b; }

  sort(vec.begin(), vec.end(),
       [](C c1, C c2) {return c1.a < c2.a;} );

  lli now=0;
  REP(i,n){
    now += vec[i].b;
    if( k<=now ){
      cout << vec[i].a << endl;
      break; 
    }
  }
  return 0;
}