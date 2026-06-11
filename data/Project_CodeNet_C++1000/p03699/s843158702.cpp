#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    int s[N];
    rep(i, N) cin >> s[i];
    int sum = 0;
    int min_num = 100; //各問題の配点で、10の倍数でなく、克一番小さい配点を格納
    int cnt = 0;
    rep(i, N){
        sum += s[i];
        if(s[i] % 10 != 0 && min_num > s[i]) min_num = s[i];
        if(s[i] % 10 == 0) cnt++;
    }
    if(cnt == N){
        cout << 0 << endl;
        return 0;
    }
    if(sum % 10 != 0) cout << sum << endl;
    else cout << sum - min_num << endl;
    return 0;
} 