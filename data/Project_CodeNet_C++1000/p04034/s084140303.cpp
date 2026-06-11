#define ll long long int

#include <bits/stdc++.h>

using namespace std;
const int N = 1E5 + 8;

vector<int> vc[N];
bool b[N];
int used[N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    fill(used, used + N, 1);
  //  cout <<used[1] <<" " ;
    b[1] = true;
    while (k--) {
        int x, y;
        cin >> x >> y;
        used[x]--;

        used[y]++;
        if (b[x]) {
            b[y] = true;
        }
        if(used[x] == 0)b[x] = false;
    }
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (b[i] && used[i] > 0 )cnt++;
    }
    cout << cnt << "\n";


    return 0;
}
