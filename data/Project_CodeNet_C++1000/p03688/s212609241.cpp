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

int a[100000];
int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    set <int> values;
    for(int i = 0; i < N; i++){
        values.insert(a[i]);
    }
    if(values.size() > 2){
        cout << "No" << endl;
        return 0;
    } 

    if(values.size() == 1){
        if(a[0] == (N - 1) || (a[0] <= N / 2)){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    if(values.size() == 2){
        auto it = values.begin();
        int smaller = *it;
        it++;
        int bigger = *it;

        int smaller_num = 0;
        int bigger_num = 0;
        for(int i = 0; i < N; i++){
            if(a[i] == smaller){
                smaller_num ++;
            } else {
                bigger_num ++;
            }
        }
        int min_color_num = smaller_num + 1;
        int max_color_num = smaller_num + bigger_num / 2;
        //cout << min_color_num << " " << max_color_num << endl;
        if(smaller < min_color_num - 1 || bigger > max_color_num){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
        return 0;
    }

    return 0;
}