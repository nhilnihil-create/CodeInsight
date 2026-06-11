#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
const int maxn = 2e5 + 5;
int f1[maxn] , f2[maxn];
int getf (int x , int f[]){
    return x == f[x] ? x : f[x] = getf(f[x] , f);
}
void mer (int a , int b , int f[])
{
    int fa = getf(a , f) , fb = getf(b , f);
    if (fa == fb) return ;
    f[fb] = fa;
}
int n , k , l;
map<pii,int> Q;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k >> l;
    for (int i = 1 ; i <= n ; i++) f1[i] = i , f2[i] = i;
    for (int i = 1 ; i <= k ; i++){
        int x , y; cin >> x >> y;
        mer(x , y , f1);
    }
    for (int i = 1 ; i <= l ; i++){
        int x , y; cin >> x >> y;
        mer(x , y , f2);
    }
    for (int i = 1 ; i <= n ; i++)
        Q[mp(getf(i , f1) , getf(i , f2))]++;
    for (int i = 1 ; i <= n ; i++){
        cout << Q[mp(getf(i , f1) , getf(i , f2))] << " ";
    }
    cout << endl;
    return 0;
}
