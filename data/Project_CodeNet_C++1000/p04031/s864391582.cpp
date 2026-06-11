#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}
int cal_cost(vi & a, int x){
    int cost = 0;
    for( int i = 0 ; i < a.size() ; i++){
        cost += ( a[i] - x) * (a[i] - x);
    }
    return cost;
}
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for ( int i  = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int min_cost = 100 * 200 * 200; 
    for(int i = - 100; i <= 100; i++){
        int cost = cal_cost(a, i);
        if( cost < min_cost){
            min_cost = cost;
        }
    }
    cout << min_cost << "\n";
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 2;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}

