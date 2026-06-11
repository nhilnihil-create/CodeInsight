#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;

int main(){
    long long N;
    cin >> N;
    long long div1=1;
    for(long long i=1;i*i<=N;i++){
        if(N%i==0) div1 = i;
    }
    long long div2=N/div1;
    long long temp = max(div1,div2);
    int ans = 0;
    while(1){
        temp/=10;
        ans++;
        if(temp==0) break;
    }
    cout << ans << endl;
    return 0;
}