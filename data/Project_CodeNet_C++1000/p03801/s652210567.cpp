#define _USE_MATH_DEFINES
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
#include <iomanip>

using namespace std;

long long a[100000];
pair <long long, int> a_ind[100000];
long long ans[100000];
int main(){
    int N;
    cin >> N;
    long long left = 0;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        left += a;
        a_ind[i] = make_pair(a, -i);
    }
    sort(a_ind, a_ind + N);

    long long cur_max = a_ind[N - 1].first;
    long long before_ind = - a_ind[N - 1].second;
    long long bigger_total = 0;
    long long bigger_num = 0;
    for(int i = N - 1; i >= 0; i--){
        if((- a_ind[i].second) >= before_ind){
            bigger_total += a_ind[i].first;
            bigger_num ++;
        } else {
            ans[before_ind] = bigger_total - a_ind[i].first * bigger_num;
            left -= bigger_total - a_ind[i].first * bigger_num;
            cur_max = a_ind[i].first;
            before_ind = - a_ind[i].second;
            bigger_num++;
            bigger_total = cur_max * bigger_num;
        }
    }
    ans[0] = left;

    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
