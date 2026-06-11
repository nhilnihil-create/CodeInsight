#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std ;

int main(){
    std::ios_base::sync_with_stdio(0);  cin.tie(NULL);  cout.tie(NULL);
    vector <int> vec(3) ;
    for(int i = 0 ; i < 3 && cin >> vec[i] ; i++) ;
    int count_5 = 0, count_7 = 0;
    for(int i = 0 ; i < 3 ; i++){
        if(vec[i] == 5) count_5++ ;
        else if(vec[i] == 7) count_7++ ;
    }
    cout << ( count_5 == 2 && count_7 == 1 ? "YES" : "NO") ;
    return 0 ;
}