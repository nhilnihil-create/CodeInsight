#include <bits/stdc++.h>

using namespace std;

const long NMAX = 100010;
const long dx[10] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2};
const long dy[10] = {0, 0, 1, 2, 0, 1, 2, 0, 1, 2};

struct Point{
    long x;
    long y;
};

struct CMP{
    bool operator()(const Point& p, const Point& q){
        if (p.x == q.x) return p.y < q.y;
        return p.x < q.x;
    }
};


long long H, W, N;
Point a[NMAX];
map<Point, int, CMP> F;
long long kq[15];

bool kiemtra(long zx, long zy){
    return zx>0 && zy>0 && zx<=H && zy<=W;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> H >> W >> N;
    for (long i=1; i<=N; ++i){
        cin >> a[i].x >> a[i].y;
        for (int j=1; j<=9; ++j){
            long xx = a[i].x + dx[j];
            long yy = a[i].y + dy[j];
            if (kiemtra(xx, yy) && kiemtra(xx-2, yy-2)){
                Point tmp = {xx, yy};
                if (F.find(tmp) != F.end()) F[tmp]++;
                else F[tmp] = 1;
            }
        }
    }
    for (auto it : F) kq[it.second]++;
    long long tmp_kq = (W-2) * (H-2);
    for (int i=1; i<=9; ++i) tmp_kq -= kq[i];
    kq[0] = tmp_kq;
    for (int i=0; i<=9; ++i) cout << kq[i] << endl;
    return 0;
}
