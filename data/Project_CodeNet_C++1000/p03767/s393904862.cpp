#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(3*n,0);

    for(int i=0;i<3*n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    long long ans=0;

    int cnt=0;
    int pos = 3*n-2;
    while(cnt<n){
        ans += a[pos];
        //cout << a[pos] << endl;
        cnt++;
        pos-=2;
    }

    cout << ans << endl;
}

