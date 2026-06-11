#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
typedef long long ll;
ll n;
ll a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    ll t1 = n/50;
    ll t2 = n%50;
    for(int i = 1; i <= 50; i++){
        a[i] = 50 - i;
        a[i]+=t1;
    }
    for(int i = 1;t2>0;t2--,i++){
        a[i]+=1;
    }
    cout << "50" <<endl;
    for(int i = 1; i <= 49; i++)
        cout << a[i] << " ";
    cout << a[50] << endl;
    return 0;
}