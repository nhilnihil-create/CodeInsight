#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    long long A, B, C;
    cin >> A >> B >> C;
    
    long long r = A % B;
    long long min_r = r;
    while(true){
        if(r == C){
            cout << "YES" << endl;
            break;
        }

        r = (r + A) % B;
        if(min_r == r){
            cout << "NO" << endl;
            break;
        }
        
        if(min_r > r){min_r = r;}
        

    }

    return 0;
}