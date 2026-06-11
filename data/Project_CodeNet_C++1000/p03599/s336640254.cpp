#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i <= F; i+=A*100) {
        for(int j = 0; i+j <= F; j+=B*100) {
            for(int k = 0; k <= (i+j)/100*E; k+=C) {
                for(int l = 0; k+l <= (i+j)/100*E; l+=D) {
                    if(i+j+k+l <= F) {
                        if(ans2 == 0) {
                            ans1 = k+l;
                            ans2 = i+j+k+l;
                        }
                        else if((double)ans1/ans2 < (double)(k+l)/(i+j+k+l)) {
                            ans1 = k+l;
                            ans2 = i+j+k+l;
                        }
                    }
                }
            }
        }
    }
    cout << ans2 << " " << ans1 << endl;
}
