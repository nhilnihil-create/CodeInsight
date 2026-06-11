#include<iostream>
#include<algorithm>

using namespace std;

long long contant[300005];

int main(){
    int N;
    long long ans = 0;
    cin >> N;
    for(int i=1; i<=3*N; i++){
        cin >> contant[i];
    }
    sort(contant+1, contant+3*N+1);
    for(int i=0; i<N; i++){
        ans+= contant[N*3-1-i*2];
    }
    cout << ans << endl;
}