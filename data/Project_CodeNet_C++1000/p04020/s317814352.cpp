#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    long long r = 0;
    for(int i = 0;i < n; i++){
        if(v[i] % 2 == 1){
            v[i]--;
            if(v[i+1]){
                v[i+1]++;
            }
        }
        r += v[i];
    }
    cout << r/2;

}
