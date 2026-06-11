#include <algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<string>
#include <sstream>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
using lll = long long;
using ull = unsigned long long;
using namespace std;

vector<vector<int>> combi(int n,int r){
  vector<vector<int>> ret;
  vector<int> tmp;
  int ii,jj;
  int cnt;

  for(ii=0;ii<pow(2,n);ii++){

    cnt = 0;
    tmp.clear();
    for(jj=0;jj<n;jj++){

      if( ((ii >> jj) & 1) == 1){
        cnt++;
        tmp.push_back(jj);
      }
      else{

      }
    }
    if(cnt == r){
      ret.push_back(tmp);
    }
  }
  return ret;
  
}
bool check(vector<lll>* c,int k){
  lll ii,prev;
  lll cnt = 0;

  for(ii=0;ii<c->size();ii++){
    if(ii==0){
      prev = c->at(0);
      cnt++;
    }
    else{
      if(c->at(ii) > prev){
        prev = c->at(ii);
        cnt++;
      }
      
    }
  }

  if(cnt>=k){
    return true;
  }
  else{
    return false;
  }

}

int main(){
  lll ii,jj,kk;
  vector<int> ret;
  int n,k;
  vector<lll> a;
  vector<lll> aft;
  cin >> n >> k;
  a.resize(n);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }

  vector<vector<int>> target;
  target = combi(n,k);
  lll min = LONG_LONG_MAX;
  lll sum;
  lll prev;
  lll up;
  up = 0;

  for(vector<int> t : target){
    sum = 0;
    up = 0;
    aft = a;
    for(ii=0;ii<t.size();ii++){
      
      if(ii != 0){

        if(a[t[ii]] <= prev){

          up = prev - a[t[ii]] +1;
          sum += prev - a[t[ii]] +1;
          
          //a[t[ii]] += prev - a[t[ii]] +1;
          

        }
        else{
          up = 0;
        }
      }

      prev = a[t[ii]] + up;
      aft[t[ii]] = prev;

      //cout << "a[" << t[ii] << "]" << a[t[ii]] << "prev" << prev <<  "up:" << up << endl;
    }
    //cout << "sum:" << sum << endl;
    
    if(sum < min && check(&aft,k)){
      min = sum;
    }
    //for(auto val : aft){
    //  cout << val << "\t" ;
    //}
    //cout << endl;
  }

  cout << min << endl;
  
  return 0;
  
}
