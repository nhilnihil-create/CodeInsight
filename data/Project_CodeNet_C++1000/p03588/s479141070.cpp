#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <cmath>

using namespace std;



int main(void){
    int n;
    cin >> n;
    vector<pair<int, int>> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(), t.end());
   // cout << t[0].first << ' '<< t[0].second;
    int count = t[0].first;
    for(int i = 0; i < n-1; i++){
        count += t[i+1].first - t[i].first;
        //cout << count << endl;
    }
    count += t[n-1].second ;
    cout << count;
    return 0;

}