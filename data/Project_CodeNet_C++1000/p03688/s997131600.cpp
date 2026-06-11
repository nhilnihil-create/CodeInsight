#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;
int cnt[100005];
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
    cin >> N;
    vector<int> a(N);
    int mx = 0;
    int mn = inf;
    rep(i,N){
        cin >> a[i];
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }
    if(mx-mn>=2){
        cout << "No" << endl;
        return 0;
    }
    if(mx==mn){
        if(a[0]!=N-1 && 2*a[0]>N){
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        return 0;
    }else{
        int A = mx;
        int x = 0;
        int y= 0;
        rep(i,N){
            if(a[i]==A-1)x++;
            else y++;
        }
        if(x<A && 2*(A-x)<=y)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}