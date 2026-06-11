#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define tr(container, it) \
        for (auto it = container.begin(); it != container.end(); it++)
#define scontains(c, x) ((c).find(x) != (c).end())   //O(log n)
#define contains(c, x) (find((c).begin(),(c).end(),x) != (c).end()) //O(n)
#define ill(_x)  ll _x;scanf("%lld",&_x);
#define idb(_x)  double _x;scanf("%lf",&_x);
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vs vector<string>
#define in0(x, a, b)((x)>=a && (x)<=b    )
#define in1(x, a, b)((x)>a && (x)<b)
#define  rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const double pi = 3.14159265358979323846;
const int INF = 0x3f3f3f3f;
const int X10 = 1024, X11 = 2048, X12 = 4096, X13 = 8196, X14 = 16392, X15 = 32786, X16 = 65536, X17 = 131072, X18 = 262144, X19 = 524288, X20 = 1048576;

class UnionFind {
private:
    vector<int> p, rank;
    int N;
    int findSet2(int i, bool* A){A[i] = 1;return (p[i] == i) ? i : (p[i] = findSet2(p[i], A));}
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
        this->N = N;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
// if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
// rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }


    int numDisjointSets(){
        set<int> s;
        bool* visited = new bool[this->N];
        memset(visited, 0, sizeof(bool)*this->N);
        for (int i = 0; i < N; ++i) {
            if(!visited[i])s.insert(findSet2(i, visited));
        }
        return s.size();
    }

    int maxElements(){
        int mx = 0;
        map<int, int> m;
        for (int i = 0; i < N; ++i) {
            m[findSet(i)] ++;
        }
        set<pair<int, int>> s;
        for(auto p : m){
            s.insert({p.second, p.first});
        }
        return s.rbegin()->first ;
    }


};


template<typename T>
bool isPrime(T n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}


template <typename A, typename B>
map<B, A> map_transform(map<A, B> m){
    map<B, A> m1;
    for(auto p : m){
        m1[p->second] = p->first;
    }
    return m1;
};

struct jump{
    int height;
    string s;

};


void _() {
    int r, c;
    cin >> r >> c;
    string s;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> s;
            if(s == "snuke")cout << (char)(j+'A') << (i+1);
        }
    }

}


int main() {
#ifdef Debug
    freopen("/home/joduskame/Desktop/cpp/IO/Input.txt", "r", stdin);
    freopen("/home/joduskame/Desktop/cpp/IO/Output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    _();
    return 0;

}






