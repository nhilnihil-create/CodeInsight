#include <bits/stdc++.h>
#include <map> // pair
using namespace std;

typedef long long ll;
#define vec vector<int>
#define vecll vector<ll>
#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define llrep(i,n)   for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define prt_dbl(i,var) cout<<fixed<<setprecision(i)<<var<<endl;
#define dpair pair<double,double>

template <typename Val>
Val gcd(Val a, Val b) {
//use ll or int for gcd
    if (b==0) return a;
    else return gcd(b, a%b);
}
template <typename Val>
Val vec_max(vector<Val> v){
  return *max_element(v.begin(),v.end());
}
template <typename Val>
Val vec_min(vector<Val> v){
  return *min_element(v.begin(),v.end());
}
template <typename Val>
void show_vec(vector<Val> *v){
  cout<<endl;
  rep(i,v->size()){
    cout<<v->at(i)<<" ";
  }
  cout<<endl;
}

template <typename Val,typename Number>
void count_vector(vector<Val>* A,vector<pair<Number,Val>>*R){
  sort(A->begin(),A->end());
  int count = 1;
  rep(i,A->size()){
    if(i<A->size()-1){
      if(A->at(i)==A->at(i+1))count++;
      else{
        R->emplace_back(count,A->at(i));
        count = 1;
      }
    }else{
      R->emplace_back(count,A->at(i));
    }
  }
}


struct Point{
  int x;
  int y;
};


bool Check(vector<Point>*Map,Point P){
  rep(i,Map->size()){
    if(P.x == Map->at(i).x && P.y == Map->at(i).y){
      return 0;
    }
  }
  return 1;
}

void move_to_t(Point s,Point t, vector<Point>*Map ,string *ans){
  Point search = s;
  int L_flag = 0;
  int D_flag = 0;
  while(1){
    int step_x = t.x - search.x;
    int step_y = t.y - search.y;

    Point P1{search.x+1, search.y};
    Point P2{search.x, search.y+1};
    Point P3{search.x-1, search.y};
    Point P4{search.x, search.y-1};
    cout<<step_x<<" "<<step_y<<endl;
    if(ans->back()=='D'||(step_x>0&&Check(Map,P1))){
      search = P1;
      ans->push_back('R');
    }else if(ans->back()=='L'||(step_y>0&&Check(Map,P2))){
      search = P2;
      ans->push_back('U');
    }else if(Check(Map,P3)){
      search = P3;
      ans->push_back('L');
    }else if(Check(Map,P4)){
      search = P4;
      ans->push_back('D');
    }else if(Check(Map,P2)){
      search = P2;
      ans->push_back('U');
    }else if(Check(Map,P1)){
      search = P1;
      ans->push_back('R');
    }

    if(search.x == t.x && search.y == t.y )break;
    Map->push_back(search);
    cout<<*ans<<endl;

  }

}

void move_to_s(Point t, Point s,vector<Point>*Map ,string *ans){
  Point search = t;
  while(1){
    int step_x = - s.x + search.x;
    int step_y = - s.y + search.y;
    Point P1{search.x-1, search.y};
    Point P2{search.x, search.y-1};
    Point P3{search.x+1, search.y};
    Point P4{search.x, search.y+1};
    cout<<step_x<<" "<<step_y<<endl;
    cout<<search.x<<" "<<search.y<<endl;
    if(ans->back()=='U'||(step_x>0&&Check(Map,P1))){
      search = P1;
      ans->push_back('L');
    }else if(ans->back()=='R'||(step_y>0&&Check(Map,P2))){
      search = P2;
      ans->push_back('B');
    }else if(Check(Map,P3)){
      search = P3;
      ans->push_back('R');
    }else if(Check(Map,P4)){
      search = P4;
      ans->push_back('U');
    }else if(Check(Map,P2)){
      search = P2;
      ans->push_back('B');
    }else if(Check(Map,P1)){
      search = P1;
      ans->push_back('L');
    }

    if(search.x == s.x && search.y == s.y )break;
    Map->push_back(search);
    cout<<*ans<<endl;
  }


}


//---------------------------------------------------------------
int main(){
  Point s;
  Point t;
  string ans;
  cin>>s.x>>s.y>>t.x>>t.y;
  int step_x = - s.x + t.x;
  int step_y = - s.y + t.y;

  rep(i,step_y){
    ans.push_back('U');
  }
  rep(i,step_x){
    ans.push_back('R');
  }
  rep(i,step_y){
    ans.push_back('D');
  }
  rep(i,step_x){
    ans.push_back('L');
  }


  ans.push_back('L');
  rep(i,step_y+1){
    ans.push_back('U');
  }
  rep(i,step_x+1){
    ans.push_back('R');
  }
  ans.push_back('D');

  ans.push_back('R');
  rep(i,step_y+1){
    ans.push_back('D');
  }
  rep(i,step_x+1){
    ans.push_back('L');
  }
  ans.push_back('U');







  cout<<ans<<endl;





}
