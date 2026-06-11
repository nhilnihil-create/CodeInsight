#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}
deque<int> p ;
long long N ; 
void solve(long long N){
    if(N == 0){
        return ;
    }
    if(N%2ll == 0){
        solve(N - 1) ;
        int k = p.size() ;
        p.push_front(k+1) ;
        // cout << "pushback " << (k+1) << endl ;
    }
    else{
        solve( (N - 1)/2ll) ;
        int k = p.size() ;
        p.push_back(k+1) ;
        // cout << "pushfront " << (k+1) << endl ;
    }
    // cout << "@ N = " << N << endl ;
}
vector<int> ans ;
int main(int argc,char* argv[]) { 
    io() ;
    #ifndef ONLINE_JUDGE
      //  freopen("inp.txt", "r", stdin) ;
        // freopen("out.txt", "w", stdout);
    #endif
    cin >> N ;
    solve(N)  ;
    while(!p.empty()){
        int f = p.front() ;
        p.pop_front() ;
        ans.push_back(f) ;
    }
    int sz = 2*ans.size() ;
    cout << sz << endl ;
    for(auto x:ans) cout << x << " " ;
    for(int i = 1 ; i <= ans.size() ; i++) cout << i << " " ;

    return 0 ; 
}