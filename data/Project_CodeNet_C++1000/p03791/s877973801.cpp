#include <iostream>

#define N_LARGE 1000000007
#define N_MAX 100000

typedef long long ll;

int x[N_MAX];

using namespace std;

int main(){
    int n, m;
    int count = 0;
    ll ans = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        count++;
        cin >> x[i];
        if(x[i]%2 == 0 && x[i]/2 < count){
            ans *= count;
            ans = ans%N_LARGE;
            //cout << i << endl;
            count--;
        }
    }
    for(int i = 1; i <= count; i++){
        ans = (ans*i)%N_LARGE;
    }
    cout << ans << endl;
}