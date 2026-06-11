#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
typedef long long LL;
const int maxn = 1e5 + 5;
LL B, A;
LL h[maxn];
LL a[maxn];

int main(){
    cin >> n;
    cin >> A >> B;
    LL l = 0, r = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &h[i]);
        r = max(r, h[i]);
    }
    while(l < r){
        LL mid = (l + r) / 2;
        LL sum = 0;
        for(int i = 1;i <= n;i++){
            a[i] = h[i];
            a[i] -= mid * B; 
            if(a[i] > 0){
                sum += (a[i] + A - B - 1) / (A - B);
            }
        } 
        if(sum <= mid){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
