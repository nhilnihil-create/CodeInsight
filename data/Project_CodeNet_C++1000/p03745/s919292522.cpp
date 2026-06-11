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
const int maxn = 1e5 + 5;
int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int s = 0;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i > 1){
            if(a[i] != a[i - 1]){
                if(a[i] < a[i - 1]){
                    if(s == -1){
                        cnt++;
                        s = 0;
                    }else{
                        s = 1;
                    }
                }else{
                    if(s == 1){
                        cnt++;
                        s = 0;
                    }else{
                        s = -1;
                    }
                }
            }
        }
    }
    cout << cnt + 1 << endl;
    return 0;
}
