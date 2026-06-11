#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define int long long

set<pair<int, int> > ydk;

signed main(){
    int h, w, n;
    cin >> h >> w >> n;

    int ans[20] = {};

    ans[0] = (h-2)*(w-2);

    int x[100010];
    int y[100010];

    set<pair<int, int> > st;

    for(int i = 0;i < n;i++){
        cin >> y[i] >> x[i];
        x[i]--;
        y[i]--;
        ydk.insert(make_pair(x[i], y[i]));

        for(int a = -2;a <= 2;a++){
            for(int b = -2;b <= 2;b++){
                int xx = x[i]+a;
                int yy = y[i]+b;
                if(0 <= xx && xx < w-2 && 0 <= yy && yy < h-2){
                    st.insert(make_pair(xx, yy));
                }
            }
        }
    }

    for(auto itr = st.begin(); itr != st.end();itr++){
        int xx = (*itr).first;
        int yy = (*itr).second;

        int cnt = 0;
        for(int a = 0;a < 3;a++){
            for(int b = 0;b < 3;b++){
                if(ydk.find(make_pair(xx+a, yy+b)) != ydk.end()){
                    cnt++;
                }
            }
        }

        ans[0]--;
        ans[cnt]++;
    }


    for(int i = 0;i <= 9;i++){
        cout << ans[i] << endl;
    }

    return 0;
}

