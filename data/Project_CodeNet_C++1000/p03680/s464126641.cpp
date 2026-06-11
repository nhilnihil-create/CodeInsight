#include <bits/stdc++.h>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N)cin >> a[i];

    int next = a[0];
    int count = 1;
    while(true){
        if(count > N){
            cout << -1 << endl;
            break;
        }

        if( next == 2 ){
            cout << count << endl;            
            break;
        }
        next = a[next - 1];
        count += 1;

    }    
    return 0;
}
