#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define val first
#define place second
const int mod = (int)1e9 + 7;
const ll INF = (ll)1e18;
const int N = (int)2e5 + 100;
const int MAXA = (int)3e6;
pair<ll, int> arr[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");


    ll w,h;
    cin >> w >> h;
    for(int i = 0;i < w;i++)cin >> arr[i].val,arr[i].place = 2;
    for(int i = 0;i < h;i++)cin >> arr[i + w].val,arr[i + w].place = 1;
    sort(arr,arr  + w + h);
    ll place1 = 0,place2 = 0;
    ll ans = 0;
    for(int i = 0;i < w + h;i++){
        if(arr[i].place == 1){
        ans += (max((w - place2 + 1), 0LL) * arr[i].val);
        place1++;
        }else{
        ans += (max((h - place1 + 1), 0LL) * arr[i].val);
        place2++;
        }
    }
    cout << ans;
    return 0;
}
