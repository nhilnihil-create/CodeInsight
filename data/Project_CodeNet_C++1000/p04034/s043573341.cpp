#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
    int n,m;
    cin >> n >> m;
    int pos[n],counter[n];
    for (int i = 0; i < n; i++){
        pos[i] = 0;
        counter[i] = 1;
    }
    pos[0] = 1;
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        if (pos[x]) pos[y] = true;
        counter[x]--;
        counter[y]++;
        if (!counter[x]) pos[x] = false;
    }
    int num = 0;
    for (int i = 0; i < n; i++) num += pos[i];
    cout << num;
}
