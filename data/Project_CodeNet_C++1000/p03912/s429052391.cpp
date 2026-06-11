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
int X[100000];
map <int, int> mod_counts;
map <int, int> mod_same_counts;
map <int, int> counts;
int main(){ 
    int N;
    int M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> X[i];
    }

    for(int i = 0; i < N; i++){
        if(counts.find(X[i]) != counts.end()){
            counts[X[i]] ++;
        } else {
            counts[X[i]] = 1;
        }
    }

    for(auto it = counts.begin(); it != counts.end(); it++){
        if(it->second % 2 == 1){
            if(mod_counts.find(it->first % M) != mod_counts.end()){
                mod_counts[it->first % M] ++;
            } else {
                mod_counts[it->first % M] = 1;
            }
            counts[it->first] --;
        }
    }

    for(auto it = counts.begin(); it != counts.end(); it++){
        if(it->second != 0){
            if(mod_same_counts.find(it->first % M) == mod_same_counts.end()){
                mod_same_counts[it->first % M] = 0;
            } 
            mod_same_counts[it->first % M] += it->second;
        }
    }

    int ans = 0;
    for(int i = 0; i < M; i++){
        if(mod_counts.find(i) == mod_counts.end()){
            mod_counts[i] = 0;
        }
        if(mod_same_counts.find(i) == mod_same_counts.end()){
            mod_same_counts[i] = 0;
        }
    }

    ans = (mod_counts[0] + mod_same_counts[0]) / 2;
    mod_same_counts[0] = 0;
    if(M % 2 == 0){
        ans += (mod_counts[M / 2] + mod_same_counts[M / 2]) / 2;
        mod_same_counts[M / 2] = 0;
    }
    for(int i = 1; i <= M / 2; i++){
        if(i == M - i){
            break;
        }
        if(mod_counts[i] > mod_counts[M - i]){
            ans += mod_counts[M - i];
            int left = mod_counts[i] - mod_counts[M - i];
            if(left < mod_same_counts[M - i]){
                ans += left;
                mod_same_counts[M - i] -= left;
            } else {
                ans += mod_same_counts[M - i];
                mod_same_counts[M - i] = 0;
            }
        } else {
            ans += mod_counts[i];
            int left = mod_counts[M - i] - mod_counts[i];
            if(left < mod_same_counts[i]){
                ans += left;
                mod_same_counts[i] -= left;
            } else {
                ans += mod_same_counts[i];
                mod_same_counts[i] = 0;
            }
        }
    }

    for(auto it = mod_same_counts.begin(); it != mod_same_counts.end(); it++){
        ans += it->second / 2;
    }
    cout << ans << endl;


    return 0;
}