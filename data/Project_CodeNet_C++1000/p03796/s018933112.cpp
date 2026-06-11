#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >>N;
    long long mod=1000000007;
    long long count=1;
    for(int i=1;i<=N;i++){
         count*=i;
         count%=mod;
    }
    cout <<count<<endl;
}