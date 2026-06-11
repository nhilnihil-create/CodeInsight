#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[305][305];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    bool b[305]{0};
    int d[305]{0};
    int ans = n;
    for(int c = 0; c < m; c++){
        int s[305]{0};
        for(int i = 0; i < n; i++) s[a[i][d[i]]]++;
        int l = 0;
        for(int i = 0; i < m; i++) l = max(l, s[i]);
        ans = min(ans, l);
        for(int i = 0; i < m; i++){
            if(s[i] == l) b[i] = true;
        }
        for(int i = 0; i < n; i++){
            while(b[a[i][d[i]]] && d[i] < m) d[i]++;
        }
    }
    cout << ans << endl;
}
