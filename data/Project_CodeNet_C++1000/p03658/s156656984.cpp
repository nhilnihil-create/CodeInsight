#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N, K, sum = 0;
    cin >> N >> K;
    vector<int> l(N);
    for(int i = 0; i < N; i++){
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    for(int j = 0; j < K; j++){
        sum += l[j];
    }
    cout << sum << endl;
}