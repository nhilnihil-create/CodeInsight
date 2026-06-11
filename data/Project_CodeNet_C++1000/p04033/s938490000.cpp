#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define ll long long
const int inf = 1e8;
const ll INF = 1e18;
const int MAXN = 6e5 + 200;
const  long double eps = 1e-9;
const long double pi = acos(-1.0);
using namespace std;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1 -1};

string check(int a, int b){
    int zero = 0;
    int otr = 0;
    for (int i = a; i <= b; i++) {
        if (i < 0) otr++;
        if (i == 0) zero++;
    }
    if (zero > 0)
        return "Zero";
    if (otr % 2)
        return "Negative";
    return "Positive";
}
void solve() {
    int a, b;
    cin >> a >> b;
    cout << check(a, b);
}


int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(40);
    //freopen("inevit.in", "r", stdin);
    //freopen("inevit.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++)
        solve();


}