#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(N+1, 1);
    vector<bool> ans(N+1, false);
    ans[1]=true;
    ans.push_back(1);
    for(int m=0; m<M; m++) {
        int x, y;
        cin >> x >> y;
        vec[x]--;
        vec[y]++;
        if(ans[x]) {
            if(vec[x]==0) ans[x]=false;
            ans[y]=true;
        }
    }
    int cnt=0;
    for(int n=1; n<=N; n++) {
        if(ans[n]) cnt++;
    }
    cout << cnt << endl;

    return 0;
    
}