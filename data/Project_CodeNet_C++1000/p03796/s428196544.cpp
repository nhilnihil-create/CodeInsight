#include<iostream>
#include<vector>
using namespace std;


int main(){
    long long power = 1;
    long long mod = 1000000000+7;
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        power *=i;
        power %= mod;
    }

    cout << power << endl;
}