#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<queue>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i=0; i<(int) (n);i++)
using ll = long long;
using P = pair<int,int>;

void solve_1(){//
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int button_id = 0;
    rep(i,n)
    {
        button_id = a[button_id] - 1;
        if (button_id == 1)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    solve_1();
    return 0;
}