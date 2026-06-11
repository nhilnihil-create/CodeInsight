#include <cassert>
//PXjUXeZStdX
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
// #include <boost/foreach.hpp>
// #include <boost/range/algorithm.hpp>
#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define ll long long
#define Sort(v) sort(all(v))
//#define INF 1e9
#define LINF (1LL<<40)
#define END return 0
#define pb push_back
#define se second
#define fi first
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define MP make_pair
#define int long long
using namespace std;
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
// int dx[]={0,1,0,-1};
// int dy[]={1,0,-1,0};
typedef pair<int,int> P;

const long long MOD=1000000007LL;
bool isupper(char c){if('A'<=c&&c<='Z')return 1;return 0;}
bool islower(char c){if('a'<=c&&c<='z')return 1;return 0;}
bool iskaibun(string s){for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-i-1])return 0;return 1;}
bool isnumber(char c){return ('0'<=c&&c<='9');}
bool isalpha(char c){return (isupper(c)||islower(c));}
template<typename T> 
void print(vector<T> v){
    for(int i=0;i<v.size();i++){
        if(i)cout<<" ";
        cout<<v[i];
    }
    cout<<endl;
}
int INF=1e18;

template<typename T>
void printendl(vector<T> v){
    for(auto date:v)cout<<date<<endl;
}

template<typename T>
void printvv(vector<vector<T>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(j)cout<<" ";
            cout<<v[i][j];
        }
        cout<<endl;
    }
}
int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    else return gcd(b,a%b);
}

struct Edge{
    int to,cost;
};

struct UnionFind{
    vector<int> par;
    UnionFind(int n){
        par.assign(n,-1);
    }
    int root(int x){
        if(par[x]<0)return x;
        else return par[x]=root(par[x]);
    }

    bool same(int a,int b){
        return root(a)==root(b);
    }

    bool merge(int a,int b){
        a=root(a);
        b=root(b);
        if(a==b)return false;

        if(par[a]>par[b])swap(a,b);
        par[a]+=par[b];
        par[b]=a;
        return true;
    }

    int size(int x){
        return -par[root(x)];
    }
};


signed main (){
    int n,k,l;
    cin>>n>>k>>l;
    UnionFind uf1(n),uf2(n);
    rep(i,0,k){
        int a,b;
        cin>>a>>b;
        a--; b--;
        uf1.merge(a,b);
    }

    rep(i,0,l){
        int a,b;
        cin>>a>>b;
        a--; b--;
        uf2.merge(a,b);
    }

    map<pair<int,int>,int> mp;
    rep(i,0,n){
        mp[pair<int,int>(uf1.root(i), uf2.root(i))]++;
    }

    rep(i,0,n){
        if(i)cout<<" ";
        cout<<mp[pair<int,int>(uf1.root(i),uf2.root(i))];
    }
    cout<<endl;
    


}
/*


*/

