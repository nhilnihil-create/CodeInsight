#include <iostream>
using namespace std;
int distance(int a, int b, int c, int d) {
    return abs(a-c) + abs(b-d);
}
int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[n], c[m], d[m];
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i=0; i<m; i++) {
        cin >> c[i] >> d[i];
    }
    int point[n], min;
    for (int i=0; i<n; i++) {
        min = distance(a[i], b[i], c[0], d[0]);
        point[i] = 1;
        for (int j=1; j<m; j++) {
            if (distance(a[i], b[i], c[j], d[j]) < min) {
                point[i] = j+1;
                min = distance(a[i], b[i], c[j], d[j]);
            }
        }
        cout << point[i] << endl;
    }
}