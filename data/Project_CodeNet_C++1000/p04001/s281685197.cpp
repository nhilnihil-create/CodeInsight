#include <bits/stdc++.h>

using namespace std;
//15min
const int N = 55;

const int mod = 1e9+7;

long long s;

long long l(long long    x){
    int cnt = 0;
    while(x){
        cnt++;
        x /= 10;
    }
    return cnt;
}

long long get(int msk){
    long long sum = 0;
    long long sofar = 0;


    long long idx = 0;
    long long tmp = s;
    long long ten = 1;
    //cout << msk << ": ";
    while(tmp){
        sum = (tmp % 10) * ten + sum;
        ten *= 10;
        if(msk & (1 << idx)){
            //cout << sum << " ";
            sofar += sum;
            sum = 0;
            ten = 1;
        }
        idx ++;
        tmp /= 10;
    }
    sofar += sum;
    //cout << sum << "\n";
    return sofar;
}

int main(){
    cin >> s;
    if(s <= 9){
        cout << s << "\n";
        return 0;
    }
    int lg10 = log10(s);
    long long ans = s;
    for(int i = 1; i < (1 << lg10); i++){
        ans += get(i);
    }
    cout << ans << "\n";
}