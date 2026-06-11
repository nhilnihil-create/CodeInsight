#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

typedef pair<int, int> P;
#define fs first
#define sc second

int main(){
    int N, M;
    cin >> N >> M;
    int a[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> a[i][j];
    }

    bool use[M + 1];
    fill(use, use + M + 1, true);

    int ans = 100000;
    for(int k = 0; k < M; k++){
        vector<int> b[N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(use[a[i][j]]) b[i].push_back(a[i][j]);
            }
        }

        map<int, int> mp;
        for(int i = 0; i < N; i++){
            mp[b[i][0]]++;
        }

        int mx_num = -1, mx = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(mx < it -> sc){
                mx = it -> sc;
                mx_num = it -> fs;
            }
        }

        /*for(int i = 0; i < N; i++){
            for(int j = 0; j < b[i].size(); j++){
                cout << b[i][j] << " ";
            }
            cout << endl;
        }*/

        //printf("mx = %d, mx_num = %d\n\n", mx, mx_num);

        ans = min(ans, mx);
        use[mx_num] = false;
    }

    cout << ans << endl;
    return 0;
}
