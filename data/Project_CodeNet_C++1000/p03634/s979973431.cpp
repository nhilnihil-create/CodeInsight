#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
using namespace std;
#define int ll
struct Node {
public:
    vector<vector<int>> to_child; // {node_number,weight}
};

bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) {
        return a[1] < b[1];
    }
    else {
        return a[0] < b[0];
    }
}

vector<int> Dijkstra(vector<Node> Graph_V, int start) {
    vector<int> Cost(Graph_V.size(), ll_INF);
    priority_queue<vector<int>, vector<vector<int>>, decltype(&comp)> pq(&comp);
    Cost[start] = 0;
    pq.push({ start,0 });
    vector<int> Max = { 0,0 }; //{NodeNumber,CostfromStart}

    while (!pq.empty()) {
        int parent = pq.top()[0]; pq.pop();
        Node u = Graph_V[parent];

        for (vector<int> child : u.to_child) {
            if (Cost[parent] + child[1] < Cost[child[0]]) {
                Cost[child[0]] = Cost[parent] + child[1];
                pq.push({ child[0],Cost[child[0]] });
            }
        }
    }

    return Cost;
}

signed main() {
    //Djikstra
    int N; cin >> N;
    vector<Node> graphV(N);

    for (int i = 0; i < N - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        graphV[a].to_child.push_back({ b,c });
        graphV[b].to_child.push_back({ a,c });
    }

    int Q, K; cin >> Q >> K;
    vector<int> cost = Dijkstra(graphV, --K);

    for (int i = 0; i < Q; i++) {
        int x, y; cin >> x >> y;
        --x; --y;
        cout << cost[x] + cost[y] << endl;
    }

}