#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;
bool used[2*100005];
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int N, x;
    cin >> N >> x;
    vector<int> ans(2 * N - 1);
    if(x==1 || x== 2*N -1){
        cout << "No" << endl;
        return 0;
    }
    if(x==2&&N==2){
        cout << "Yes" << endl;
        cout << 1 << " " << 2 << " " << 3 << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int mid = ans.size() / 2;
    if(x<2*N-2){
        ans[mid] = x;
        used[x] = 1;
        ans[mid + 1] = x + 1;
        used[x+1] = 1;
        ans[mid - 1] = x - 1;
        used[x-1] = 1;
        ans[mid - 2] = x + 2;
        used[x+2] = 1;
        int cnt = 1;
        rep(i,2*N-1){
            if(ans[i]==0){
                while(used[cnt]==1)cnt++;
                ans[i] = cnt;
                cnt++;
            }
        }
    }else if(x=2*N-2){
        ans[mid] = x;
        ans[mid-1] = x+1;
        ans[mid+1] = x-2;
        ans[mid-2] = x-1;
        int cnt = 1;
        rep(i,2*N-1){
            if(ans[i]==0){
                while(used[cnt]==1)cnt++;
                ans[i] = cnt;
                cnt++;
            }
        }
    }
    for(auto x:ans)cout << x << endl;
}