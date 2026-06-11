#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    int t[200001];
    long long time = 0;
    for(int i = 0; i < N; i++) cin >> t[i];
    for(int i = 1; i < N; i++){
        if((t[i]-t[i-1]) >= T) time += T;
        else time += (t[i]-t[i-1]); 
    }
    time += T;
    cout << time << endl;
    return 0;
}