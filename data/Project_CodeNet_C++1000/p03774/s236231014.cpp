#include <iostream>
#include <cmath>
using namespace std;
struct Point{
    int x, y;
};
int dist(Point a, Point b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    Point points[N];
    Point gather[M];
    for(int i = 0; i < N; ++i){
        cin >> points[i].x >> points[i].y;
    }
    for(int i = 0; i < M; ++i){
        cin >> gather[i].x >> gather[i].y;
    }
    int ans[N];
    for(int i = 0; i < N; ++i){
        int now = 1e9;
        int idx;
        for(int j = 0; j < M; ++j){
            if(now > dist(points[i], gather[j])){
                now = dist(points[i], gather[j]);
                idx = j+1;
            }
        }
        ans[i] = idx;
    }
    
    for(int x : ans) cout << x << endl;
    return 0;
}