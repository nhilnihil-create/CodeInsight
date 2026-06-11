#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;
const int maxn = 505;

pi x[maxn];
bool vis[maxn * maxn];
int a[maxn * maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> x[i].fi;
        x[i].se = i;
    } 
    sort(x + 1,x + 1 + n);
    int sum = 0;
    int sum1 = 0;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        if(sum + x[i].se > x[i].fi)
            flag = false;  
        if(n * (n - 1) / 2 + sum1 + i < x[i].fi)
            flag = false;
        sum += x[i].se;
        sum1 += (n - x[i].se);
    }
    if(!flag){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        int j = 1;
        for(int i = 1;i <= n;i++){
            for(int k = 1;k < x[i].se;k++){
                while(vis[j]){
                    j++;
                }
                a[j] = x[i].se;
                vis[j++] = true;
            } 
            a[x[i].fi] = x[i].se; 
            vis[x[i].fi] = true;
        }
        for(int i = 1;i <= n;i++){
            for(int k = x[i].se + 1;k <= n;k++){
                while(vis[j]){
                    j++;
                }
                a[j] = x[i].se;
                vis[j++] = true;
            }
        }
        for(int i = 1;i <= n * n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
