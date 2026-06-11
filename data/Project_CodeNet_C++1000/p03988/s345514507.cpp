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

int a[100];
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    int max_a = 0;
    int min_a = INT_MAX;
    map <int, int> a_count;
    for(int i = 0; i < N; i++){
        max_a = max(max_a, a[i]);
        min_a = min(min_a, a[i]);
        if(a_count.find(a[i]) != a_count.end()){
            a_count[a[i]] += 1;
        } else {
            a_count[a[i]] = 1;
        }
    }


    if(min_a < max_a / 2){
        cout << "Impossible" << endl;
        return 0;
    }

    int lowest;
    if(max_a % 2 == 0){
        lowest = max_a / 2;
    } else {
        lowest = max_a / 2 + 1;
    }

    if(max_a % 2 == 0 && a_count[lowest] != 1){
        cout << "Impossible" << endl;
        return 0;
    }
    if(max_a % 2 == 1 && a_count[lowest] != 2){
        cout << "Impossible" << endl;
        return 0;
    }
    
    if(a_count[max_a] == 1){
        cout << "Impossible" << endl;
        return 0;
    }

    for(int i = lowest; i < max_a; i++){
        if(a_count.find(i) == a_count.end()){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << "Possible" << endl;
    return 0;
}