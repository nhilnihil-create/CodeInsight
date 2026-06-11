#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = unsigned long long int;
using namespace std;

class Point {
  public:
    long long x_, y_;
    Point(long long x, long long y) : x_{x}, y_{y} {}
    long long operator*(Point o) { return abs(x_ - o.x_) + abs(y_ - o.y_); }
};

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;

    vector<Point> students;
    rep(i, n) {
        li a, b;
        cin >> a >> b;
        students.push_back(Point(a, b));
    }

    vector<Point> checkpoints;
    rep(i, m) {
        li c, d;
        cin >> c >> d;
        checkpoints.push_back(Point(c, d));
    }

    rep(i, n) {
        li min_dist = 100000001 * 2;
        int coord = 1;
        rep(j, m) {
            li cur_dist = students.at(i) * checkpoints.at(j);
            if (min_dist > cur_dist) {
                min_dist = cur_dist;
                coord = j + 1;
            }
        }
        cout << coord << endl;
    }
}