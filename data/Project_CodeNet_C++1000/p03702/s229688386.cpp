
/**
*
* Author : MeGa
*
*/
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string.h>

using namespace std;

vector<int>v;
int n;
long long a,b;
long long solve(long long mid){

    long long aa = mid;
    long long dif = a-b;
    for(int i = 0; i < v.size(); i ++){
        long long cur = v[i]-(b*mid);
        
        if(cur > 0){
            long long val = (cur+dif -1)/ dif;
            if( val > aa)
                return false;
            else{
                 aa-= val;
            }
        }
    }
    
    return true;

}

int main(){

#ifndef ONLINE_JUDGE
    //freopen("in","r",stdin);
#endif
     ios::sync_with_stdio(false);
     cin.tie(0);
     priority_queue<pair<int,int> >pq;
     
     
     cin>>n>>a>>b;
     
     for(int i = 0 ; i < n; i ++){
        int s;
        cin>>s;
        v.push_back(s);
     }
     
     
     sort(v.begin(),v.end());

     long long left = 0  , right = 1e9+10;
     long long ans = 0;
     while(left < right){
         long long mid = left + (right - left)/2;
        // cerr<<mid<<endl;
         if(solve(mid)){
             right = mid-1;
             ans = mid;
         }else{
             left = mid + 1;
         }
     }
     
     
     if(solve(ans-1)){
         cout<<ans-1<<endl;
     }else{
         cout<<ans<<endl;
     }
    


     


    
   

}