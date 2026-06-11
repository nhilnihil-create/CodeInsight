#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main()
{   
    ll N ;
    cin >> N ;
    ll a[N] ;
    ll lv[9] ;
    for(ll j = 0 ; j < 9 ; j++ ){ 
        lv[j] = 0 ;
    }
    for(ll i = 0 ; i < N ; i++){
        cin >> a[i] ;
        if(a[i] < 400 ) lv[0]++ ;
        else if(a[i] < 800) lv[1]++ ;
        else if(a[i] < 1200) lv[2]++ ;
        else if(a[i] < 1600) lv[3]++ ;
        else if(a[i] < 2000) lv[4]++ ;
        else if(a[i] < 2400) lv[5]++ ;
        else if(a[i] < 2800) lv[6]++ ;
        else if(a[i] < 3200) lv[7]++ ;
        else lv[8]++ ;
    }
    
    ll ans = 0 ;
    for(ll j = 0 ; j < 8 ; j++){
        //cout << lv[j] << endl;
        if(lv[j] > 0){
          ans++ ;
        }
    }
    if(ans == 0){
        cout << 1 <<" "<< endl;
    }else{
    cout << ans << " " ;
    }
    ans += lv[8] ;
    
    cout << ans << endl;
    


    

    return 0;
}