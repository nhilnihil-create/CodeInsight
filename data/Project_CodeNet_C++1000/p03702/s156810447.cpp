#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;
long long h[100000];
int main(){
    int N;
    long long A;
    long long B;

    cin >> N >> A >> B;
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }

    long long left = 0;
    long long right = 10000000000;
    while(left + 1 < right){
        long long mid = (left + right) / 2;
        long long base_damage = mid * B;
        bool all_dead = true;
        long long left_mp = mid;
        for(int i = 0; i < N; i++){
            long long stamina = h[i] - base_damage;
            if(stamina <= 0){
                continue;
            }

            int required_mp;
            if(stamina % (A - B) == 0){
                required_mp = stamina / (A - B);
            } else {
                required_mp = stamina / (A - B) + 1;
            }
            if(left_mp < required_mp){
                all_dead = false;
                break;
            } else {
                left_mp -= required_mp;
            }
        }

        if(all_dead){
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
    return 0;
}
