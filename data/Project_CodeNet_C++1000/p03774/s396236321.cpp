#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 50;
static const int INF = 1e+9;
int a[MAX], b[MAX], c[MAX], d[MAX];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < m; i++){
        cin >> c[i] >> d[i];
    }
    for(int i = 0; i < n; i++){
        int dist = INF;
        int ans = 1;
        for(int j = 0; j < m; j++){
            //printf("%d %d\n", abs(a[i]-c[j]), abs(b[i]-d[j]));
            if(dist > abs(a[i]-c[j]) + abs(b[i]-d[j])){
                dist = abs(a[i]-c[j]) + abs(b[i]-d[j]);
                ans = j+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}