#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int MAXN = 200000;

/*
int N, M;

struct Edge {
    int to;
    int weight;
    int next;
};

vector<Edge> edges(MAXN);
vector<int> head(MAXN, -1);
vector<int> matchingx(MAXN, -1);
vector<int> matchingy(MAXN, -1);
vector<bool> check(MAXN);
vector<int> dis(MAXN);
vector<bool> vis(MAXN, false);

int cnt = 1;

void addEdge(int from, int to, int weight) {
    edges[cnt].to = to;
    edges[cnt].weight = weight;
    edges[cnt].next = head[from];
    head[from] = cnt++;
}

bool dfs(int u) {
    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;
        if (!check[v]) {
            check[v] = true;
            if (matchingy[v] == -1 || dfs(matchingy[v])) {
                matchingy[v] = u;
                matchingx[u] = v;
                return true;
            }
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    fill(matchingx.begin(), matchingx.end(), -1);
    fill(matchingy.begin(), matchingy.end(), -1);
    for (int u = 1; u <= N; ++u) {
//        if (matchingx[u] == -1) {
        {
            fill(check.begin(), check.end(), false);
            if (dfs(u)) {
                ++ans;
            }
        }
    }
    return ans;
}

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<>> que;
    fill(dis.begin(), dis.end(), INF);
    dis[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        cout << "pop " << p.second << endl;
        int u = p.second;
        if (dis[u] < p.first) continue;
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            if (dis[v] > dis[u] + edges[i].weight) {
                dis[v] = dis[u] + edges[i].weight;
                cout << "push " << v << endl;
                que.push(P(dis[v], v));
            }
        }
    }
}

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int val_) : val(val_) {}
};

//int dfs(int cur, int a, int b, int c, const vector<int> &nums) {
//    if (cur >= N) {
//        return (min({a, b, c}) > 0 ? (abs(a - A) + abs(b - B) + abs(c - C) - 30) : INF);
//    }
//    int ret0 = dfs(cur + 1, a, b, c, nums);
//    int ret1 = dfs(cur + 1, a + nums[cur], b, c, nums) + 10;
//    int ret2 = dfs(cur + 1, a, b + nums[cur], c, nums) + 10;
//    int ret3 = dfs(cur + 1, a, b, c + nums[cur], nums) + 10;
//    return min({ret0, ret1, ret2, ret3});
//}

class Solution {
    using Interval = pair<int, int>;
public:
    vector<string> summaryRanges(const vector<int> &nums) {
        if (nums.empty()) return {};
        for (auto &x : nums) {
            addNums(x);
        }
        auto intervals = getIntervals();
        vector<string> res;
        for (auto &v : intervals) {
            res.push_back(toString(v));
        }
        return res;
    }

private:
    unordered_set<int> st;
    unordered_map<int, int> mp;
    void addNums(int val) {
        if (st.count(val)) return;
        int left = val;
        int right = val;
        if (val > INT_MIN && st.count(val - 1)) {
            left = mp.at(val - 1);
            mp.erase(val - 1);
        }
        if (val < INT_MAX && st.count(val + 1)) {
            right = mp.at(val + 1);
            mp.erase(val + 1);
        }
        mp[left] = right;
        mp[right] = left;
        st.insert(val);
    }
    vector<Interval> getIntervals() {
        vector<Interval> res;
        for (auto &v : mp) {
            if (v.first <= v.second) {
                res.push_back(v);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    string toString(const Interval &i) {
        string res;
        if (i.first == i.second) {
            res = to_string(i.first);
        } else {
            res = to_string(i.first) + "->" + to_string(i.second);
        }
        return res;
    }
};

struct HuffmanNode : std::enable_shared_from_this<HuffmanNode> {
    typedef std::shared_ptr<HuffmanNode> HuffmanNodePtr;
    int weight;
    HuffmanNodePtr leftChild;
    HuffmanNodePtr rightChild;
    HuffmanNodePtr parent;
    explicit HuffmanNode(int weight_) : weight(weight_), leftChild(nullptr), rightChild(nullptr) {}
    bool operator<(const HuffmanNode &rhs) const {
        return weight > rhs.weight;
    }
};

//struct cmp {
//    bool operator () (const HuffmanNodePtr x, const HuffNode* y) {
//        return x->weight > y->weight;
//    }
//};

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        this->k = k;
        for (auto &x : nums) {
            add(x);
        }
    }

    int add(int val) {
        maxHeap.push(-val);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
        return -maxHeap.top();
    }
private:
    priority_queue<int> maxHeap;
    int k;
};

int bfs() {
    queue<P> que;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            dis[i][j] = INF;
        }
    }
    dis[sx][sy] = 0;
    que.push(P(sx, sy));
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        if (p.first == gx && p.second == gy) break;
        for (int i = 0; i < 4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && dis[nx][ny] == INF) {
                que.push(P(nx, ny));
                dis[nx][ny] = dis[p.first][p.second] + 1;
            }
        }
    }
    return dis[gx][gy];
}


class UnionFind {
    vector<int> par;
public:
    explicit UnionFind(int n) : par(n, -1) {}

    int root(int a) {
        if (par[a] < 0) {
            return a;
        }
        return par[a] = root(par[a]);
    }

    int size(int a) {
        return -par[root(a)];
    }

    void unite(int a, int b) {
        a = root(a);
        b = root(b);
        if (a != b) {
            if (size(a) < size(b)) {
                swap(a, b);
            }
            par[a] += par[b];
            par[b] = a;
        }
    }
};

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
*/

vector<char> maze(10000 * 10000);

int main() {
    maze[0] = 'a';
    ll n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] == i + 1) {
            ++ans;
            swap(nums[i], nums[i + 1]);
        }
    }
    if (nums[n - 1] == n) ++ans;
    cout << ans << endl;
    return 0;
}