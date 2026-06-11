#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
    int N, K;
    int I[100];
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> I[i];

    int sum = 0;

    sort(I, I + N, greater<int>());
    
    for(int i = 0; i < K; i++)
        sum += I[i];
    
    cout << sum << endl;

    return 0;
}