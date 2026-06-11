#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = 0;
    int T[n];
    for(int i=0;i<n;i++){
        cin >> T[i];
        sum += T[i];
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int p,x;
        cin >> p >> x;
        p--;
        cout << sum - T[p] + x << endl;
    }
}