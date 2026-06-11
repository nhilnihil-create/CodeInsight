#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int c = 0;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int p = 0;
    while(p < N){
        int x = A[p];
        int f = 0; 
        while(p < N && A[p] == x){
            f++;
            p++;
        }
        if(f%2 == 1) c++;
    }
    cout << c << endl;

    return 0;
}