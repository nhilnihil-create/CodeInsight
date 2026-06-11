
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

string s;



// O 1
// X 0
#define S  0
#define W  1
bool solve(vector<pair<int,int> >&v){
    while(v.size() < s.size()){
        
        int prev = v[v.size()-2].second;
        if(s[v.back().first] == 'x' ){
                if(v.back().second == S)
                    v.push_back(make_pair((v.back().first+1)%s.size(),1-prev));
                else
                    v.push_back(make_pair((v.back().first+1)%s.size(),prev));
        }else{
             if(v.back().second == S)
                    v.push_back(make_pair((v.back().first+1)%s.size(),prev));
                else
                    v.push_back(make_pair((v.back().first+1)%s.size(),1-prev));
        }
    }

    vector<char>ans(v.size(),-1);
    for(int i = 0; i < v.size();i++){
        ans[v[i].first] = (v[i].second)? 'W' : 'S';
    }
    for(int i = 0; i < ans.size(); i ++){   
        int idx  = i;
        char prevSign = ans[(idx-1+ans.size())%ans.size()];
        char nextSign = ans[(idx+1)%ans.size()];

   //     cerr<<s[idx]<<" "<<prevSign<<" "<<nextSign<<" "<<i<<" "<<ans[idx]<<endl;
        if(ans[idx] == 'S'){
                if(s[idx] == 'o'){
                        if(prevSign != nextSign)
                            return false;
                }else{
                    if(prevSign == nextSign)
                            return false;
                }
        }else{
                if(s[idx] == 'x'){
                        if(prevSign != nextSign)
                            return false;
                }else{
                    if(prevSign == nextSign)
                            return false;
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
     int n;
     cin>>n;
     cin>>s;
     for(int i = 0 ; i < s.size(); i ++){
         
         if(s[i] == 'x'){

             int left = (i-1 + s.size()) % s.size();
             int cur = i ;
             int right = (i+1) % s.size();
             bool found = false;
             for(int ii = 0 ; ii <= 1; ii++){
                 for(int j = 0 ; j <= 1; j++){
                     for(int k = 0; k <= 1 ; k++){
                         
                             vector<pair<int,int> >v;
                             v.push_back(make_pair(left,j));
                             v.push_back(make_pair(cur,ii));
                             v.push_back(make_pair(right,k));
                             if(solve(v)){
                                    found = true;
                                    vector<char>ans(s.size(),0);
                                    for(int i = 0; i < v.size();i ++){
                                        ans[v[i].first] = (v[i].second ? 'W' : 'S');
                                    }
                                    //cout<<"hola"<<endl;
                                    for(int i = 0; i < ans.size();i++){
                                        cout<<ans[i];
                                    }
                                  //  cout<<endl;
                                   return 0;
                                    
                             }
                         

                     }
                 }
             }
             break;
                    
         }
     }
     bool isAllO = true;
     for(char c : s){
         if(c == 'x'){
            isAllO = false;
         }
     }
     
     if(isAllO){
         for(int i = 0 ; i < s.size();i++){
             cout<<"S";
         }
     }else{
         cout<<-1<<endl;
     }


    
   

}