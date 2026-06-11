#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

template <class T> class SegmentTree {
public:
  SegmentTree(const int n, const T id, function<T(T, T)> op,
              function<T(T, T)> updateOp);
  void update(const int index, const T value);
  T find(const int l, const int r);

private:
  int leftChildIndex(const int parent);
  int rightChildIndex(const int parent);
  int parent(const int child);
  int leaf(const int index);
  T query(const int l, const int r, const int node, const int al, const int ar);

private:
  vector<T> data;
  int leafNum;
  T id;
  function<T(T, T)> op;
  function<T(T, T)> updateOp;
};

template <class T>
SegmentTree<T>::SegmentTree(const int n, const T id, function<T(T, T)> op,
                            function<T(T, T)> updateOp)
    : id(id), op(op), updateOp(updateOp) {
  leafNum = 1;
  while (leafNum < n)
    leafNum *= 2;
  data = vector<T>(2 * leafNum - 1, id);
}

template <class T> int SegmentTree<T>::leftChildIndex(const int parent) {
  return parent * 2 + 1;
}

template <class T> int SegmentTree<T>::rightChildIndex(const int parent) {
  return parent * 2 + 2;
}

template <class T> int SegmentTree<T>::parent(const int child) {
  return (child - 1) / 2;
}

template <class T> int SegmentTree<T>::leaf(const int index) {
  return index + leafNum - 1;
}

// [l,r)で探す
template <class T> T SegmentTree<T>::find(const int l, const int r) {
  return query(l, r, 0, 0, leafNum);
}

template <class T>
T SegmentTree<T>::query(const int l, const int r, const int node, const int al,
                        const int ar) {
  if (r <= al || ar <= l)
    return id;
  if (l <= al && ar <= r)
    return data[node];
  int mid = (al + ar) / 2;
  T leftValue = query(l, r, leftChildIndex(node), al, mid);
  T rightValue = query(l, r, rightChildIndex(node), mid, ar);
  return op(leftValue, rightValue);
}

template <class T> void SegmentTree<T>::update(const int index, const T value) {
  int i = leaf(index);
  data[i] = updateOp(data[i], value);
  while (i > 0) {
    i = parent(i);
    data[i] = op(data[rightChildIndex(i)], data[leftChildIndex(i)]);
  }
}

// [l,r]で考えている。1-index
ll rec(ll l, ll r, SegmentTree<pair<ll, int>> &seg, const vl &data) {
  if (l == r)
    return data[l - 1];
  if (l > r) {
    return 0;
  }
  auto mn = seg.find(l - 1, r);
  return mn.first * (mn.second - l + 1) * (r - mn.second + 1) +
         rec(l, mn.second - 1, seg, data) + rec(mn.second + 1, r, seg, data);
}

int main() {
  int n;
  cin >> n;
  vl a(n);
  REP(i, n) { cin >> a[i]; }
  SegmentTree<pair<ll, int>> seg(
      n, make_pair((1LL << 31) - 1, -1),
      [](pair<ll, int> a, pair<ll, int> b) -> pair<ll, int> {
        return (a.first < b.first ? a : b);
      },
      [](pair<ll, int> a, pair<ll, int> b) -> pair<ll, int> {
        return (a.first < b.first ? a : b);
      });

  REP(i, n) { seg.update(i, make_pair(a[i], i + 1)); }
  cout << rec(1, n, seg, a) << endl;
}
