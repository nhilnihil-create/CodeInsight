#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    int count =0;
    for(int i=0; i<N; i++){
        int val = a[i];
        if(i+1 == a[val-1]){
            count += 1;
        }
    }

    cout << count/2 << endl;
    return 0;
}