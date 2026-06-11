#include <iostream>
#include <vector>
using namespace std;
int n, l;
vector<int> x;
vector< vector<int> > nxt;

void cal(){
    int lim = 1;
    for(int i=0;i<n;i++){
        while(lim+1<n && x[lim+1]-x[i] <= l){
            lim++;
        }
        nxt[i][0] = lim;
    }

    for(int k=0;k<18-1;k++){
        for(int i=0;i<n;i++){
            nxt[i][k+1] = nxt[nxt[i][k]][k];
        }
    }
}

int solve(int a, int b){
    if(a == b)return 0;
    if(a > b)return solve(b, a);
    if(nxt[a][0] >= b)return 1;
    int ng = 0, ok = 18-1;
    while(ng+1 < ok){
        int mid = (ng + ok) / 2;
        if(nxt[a][mid] >= b)ok = mid;
        else ng = mid;
    }
    return (1<<ng) + solve(nxt[a][ng], b);
}

int main() {
    int q;
    cin >> n;
    x.assign(n, 0);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    cin >> l >> q;
    nxt.assign(n, vector<int>());
    for(int i=0;i<n;i++){
        nxt[i].assign(18, n-1);
    }
    cal();
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        cout << solve(--a, --b) << endl;
    }

	return 0;
}
