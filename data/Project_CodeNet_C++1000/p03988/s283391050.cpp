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
int arr[N],cnt[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int n;
    cin >> n;
    bool ok = 1;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    sort(arr + 1,arr + 1 + n);
    int num = 0;
    for(int i = 1;i <= n;i++){
        if((arr[i] - (arr[n] / 2)) < 0)ok = 0;
    }
    if(arr[1] == arr[2] && arr[2] == arr[3])ok = 0;
    if(arr[1] == arr[2] && ((arr[1] - (arr[n] / 2)) != 1))ok = 0;
    if(arr[1] != arr[2] && (arr[1] != (arr[n] / 2)))ok = 0;
    for(int i = 1;i <= n;i++)cnt[arr[i]]++;
    for(int i = 1;i <= n;i++){
        if(!(cnt[arr[i]] >= 2 || arr[i] == arr[1]))ok = 0;
    }
    int st = -1;
    if(arr[1] == arr[2])st = 1; else st = 0;
    for(int i = st + 1;i <= (arr[n] / 2);i++){
        if(cnt[i + (arr[n] / 2)] < 2){
                ok = 0;
                break;
        }
    }
    if(ok)cout << "Possible"; else cout << "Impossible";
    return 0;
}
