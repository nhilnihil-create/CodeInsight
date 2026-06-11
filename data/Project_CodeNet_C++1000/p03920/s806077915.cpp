#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> solve (int n){
    long long sum = 0;
    long long max_int = 0;
    long long num;
    priority_queue<int, vector<int>, greater<int>> ret;
    for (long long i = 1; i <= n; ++i){
        sum += i;
        if(sum >= n){
            max_int = i;
            break;
        }
    }
    long long rest = n;
    num = max_int;
    while(rest > 0){
        if(rest - num >= 0){
            ret.push(num);
            rest -= num;
        }
        num--;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> answer = solve(n);
    while(!answer.empty()){
        int ans = answer.top();
        answer.pop();
        cout << ans << endl;
    }
    return 0;
}