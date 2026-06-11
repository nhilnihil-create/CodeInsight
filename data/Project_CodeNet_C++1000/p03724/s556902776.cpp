#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int m;
    cin >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        arr[x]++, arr[y]++;
    }
    int f = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] %2 == 1) f = 1;
    }
    cout << (f == 1? "NO" : "YES");
}
