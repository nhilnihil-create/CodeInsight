#include<iostream>
#define MAX 100010
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long c[MAX] = {0};
    for(int i = 0;i < n;i++){
        long long a,b;
        cin >> a >> b;
        c[a] += b;
    }

    for(int ans = 0;ans < MAX;ans++){
        if(k <= c[ans]){
            cout << ans << endl;
            break;
        }
        k -= c[ans];
    }
    return 0;
}