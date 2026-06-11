#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <cmath>
using namespace std;
#define MAXSIZE 100005
#define PI 3.141592653589793
#define MOD_CONST 1000000007
using lli = long long int;
using PII = pair<int, int>;

lli n, a, b;

vector<lli> row(55);
vector<vector<lli>> comb(55, row);

lli calc_comb(lli n, lli r){
    if(n < r){
        return 0;
    }
    
    if(comb[n][r] > 0){
        return comb[n][r];
    }
    
    if(r == 0){
        return comb[n][r] = 1;
    }
    
    if(r * 2 > n){
        return comb[n][r] = calc_comb(n, n - r);
    }
    
    return comb[n][r] = calc_comb(n - 1, r) + calc_comb(n - 1, r - 1);
}

int main(){
    cin >> n >> a >> b;
    
    vector<lli> v(n);
    for(lli i = 0; i < n; ++i){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end(), greater<lli>());
    
    lli num_upper_a_eq_ini = 0;
    lli num_eq_ini = 0;
    lli num_upper_a_eq_a1 = 0;
    lli num_eq_a1 = 0;
    
    lli v_sum = 0;
    for(lli i = 0; i < n; ++i){
        if(v[i] == v[0]){
            if(i < a){
                // 上位a個中何個が初項と等しいかをカウント
                num_upper_a_eq_ini++;
            }
            
            // 全要素中何個が初項と等しいかをカウント
            num_eq_ini++;
        }
        
        if(v[i] == v[a - 1]){
            if(i < a){
                // 上位a個中何個が第a-1項と等しいかをカウント
                num_upper_a_eq_a1++;
            }
            
            // 全要素中何個が第a-1項と等しいかをカウント
            num_eq_a1++;
        }
        
        if(i < a){
            // 上位a個の価値の合計を計算
            v_sum += v[i];
        }
    }
    
    printf("%.15lf\n", 1.0 * v_sum / a);
    
    if(v[0] != v[a - 1]){
        cout << calc_comb(num_eq_ini, num_upper_a_eq_ini) * calc_comb(num_eq_a1, num_upper_a_eq_a1)  << endl;
    }else{
        lli patterns_sum = 0;
        for(lli i = a; i <= min(b, num_eq_ini); ++i){
            patterns_sum += calc_comb(num_eq_ini, i);
        }
        cout << patterns_sum << endl;
    }
    return 0;
}
