#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <functional>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
int main(){
    int h,w;
    cin >> h >> w;
    int n;
    cin >> n;
    queue<int> que;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        que.push(a);
    }

    vector<vector<int>> ans(h,vector<int>(w));

    int now = 1;
    int cnt = que.front();
    que.pop();
    for(int i = 0;i < h;i++){
        if(i % 2 == 0){
            for(int j = 0;j < w;j++){
                ans[i][j] = now;
                cnt--;
                if(cnt == 0 && que.size()){
                    now++;
                    cnt = que.front();
                    que.pop();
                }
            }
        }
        else{
            for(int j = w-1;j >= 0;j--){
                ans[i][j] = now;
                cnt--;
                if(cnt == 0 && que.size()){
                    now++;
                    cnt = que.front();
                    que.pop();
                }
            }
        }
    }

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
