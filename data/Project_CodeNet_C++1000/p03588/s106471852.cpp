#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector<pair<long long, long long>> scores(n);
    for (int i=0;i<n;i++){
        long long a, b;cin>>a>>b;
        scores[i] = make_pair(a, b);
    }
    sort(scores.begin(), scores.end(), greater<pair<long long, long long>>());
    cout << scores[0].first + scores[0].second << endl;
    return 0;

}