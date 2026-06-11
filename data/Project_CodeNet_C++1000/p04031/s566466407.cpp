#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

int main(){
    int N, temp;
    cin >> N;
    vector<int> A;
    for(int i = 0; i < N; i++){
        cin >> temp;
        A.push_back(temp);
    }
    double average = accumulate(A.begin(), A.end(), 0) / double(A.size());
    average = round(average); //平均を四捨五入する。
    
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += (average - A[i])*(average - A[i]);
    }
    cout << ans << endl;
}