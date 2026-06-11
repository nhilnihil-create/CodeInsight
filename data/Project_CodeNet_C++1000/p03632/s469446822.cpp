#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    vi a(4);
    rep(i,4)cin>>a[i];
    
    vi robot(102);
    rep(i,4){
        if(i%2==0)robot[a[i]]++;
        else robot[a[i]]--;
    }
    
    for(int i=1; i<=100; i++){
        robot[i] += robot[i-1];
    }
    
    sort(robot.begin(), robot.end());
    int itr = robot.end() - lower_bound(robot.begin(), robot.end(), 2);
    
    cout << itr << endl;
    
    return 0;
}