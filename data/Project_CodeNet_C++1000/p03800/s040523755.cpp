
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>
 
 
#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s
 
typedef long long ll;
 
using namespace std;

ll modd = 1000*1000*1000+7;

ll binary_search(function<bool(ll)> func, ll start, ll end) {
    /*      func:int ->bool
            returns smallest int x where func(x) evaluates to true, searches in [start,end), it is assumed the values are false, .. , false, true ...
             */
    if (end <= start) {   return end;  }   // has to be here, otherwise func(end-1) in next line could be a problem
    if (!func(end-1)) {  return end;  }
    while (end-start>1) {
        ll mid = (start+end)/2;
        if (func(mid)) {  end = mid;  } else { start = mid;   }
    }
    if (func(start)) {  return start;  } else {  return end;   }
};


int binomialmod2(ll a, ll b) {
    if ((b<0) || (b>a)) {  return 0;  }
    int ret = 1;
    while (b>0) {
        int digb = b%2, diga = a%2;
        a/=2; b/=2;
        if (digb>diga) { ret = 0; break; }
    }
    return ret;
};

int no_of_pts(vector<pair<ll,ll>>& pts, ll y_min, ll x) {  // return no of pts less or equal than x (mod 2)
  int ret = 0;
  for(auto p : pts) {
      ll x_ = p.first, y_ = p.second;
      if ((x >= x_) && (x <= x_+y_-y_min)) {
          ll a = y_-y_min, b = x-x_;
          ret += binomialmod2(a-1,b);
          ret = ret % 2;
      }
  }
  return ret;
};

int main()   {

    ios_base::sync_with_stdio(false);

    cout.precision(17);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
 
//    auto start = chrono::steady_clock::now();
  
//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n);
        readstring(s);
        vector<int> answers;
        forr(i,0,n) {
            answers.push_back(s[i]=='o' ? 0 : 1);
        }
        bool poss = false;
        vector<int> animals(n);

        if (n%3==0) {
            forr(i,0,2) {
                forr(j,0,2) {
                    forr(k,0,2) {
                        animals[0] = i;
                        animals[1] = j;
                        animals[2] = k;
                        for(int i = 3; i < n; ++i) {
                            animals[i] = animals[i-3] ^ (answers[i-2] ^ answers[i-1]);
                        }
                        bool problem = false;
                        forr(i,0,n) {
                            problem = (((animals[i]^animals[(i+1)%n])^animals[(i+2)%n])!=answers[(i+1)%n]);
                            if (problem) {break;}
                        }
                        poss = !problem;
                        if (poss) {break;}
                    }
                    if (poss) {break;}
                }
                if (poss){break;}
            }            
        } else {
            forr(i,0,2) {
                animals[0] = i;
                for(int i = 0; i < 3*n; i+=3) {
                    animals[(i+3)%n] = animals[i%n] ^ (answers[(i+1)%n]^answers[(i+2)%n]);
                }
                bool problem = false;
                forr(i,0,n) {
                    problem = (((animals[i]^animals[(i+1)%n])^animals[(i+2)%n])!=answers[(i+1)%n]);
                    if (problem) {break;}
                }
                poss = !problem;
                if (poss) {break;}
            }
        }

        if (!poss) {
            cout << -1 << endl;
        } else {
            forr(i,0,n) {
                cout << (animals[i]==0 ? 'S' : 'W');
            }
            cout << endl;
        }

    }
 
//    auto end = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
 
    return 0;
}
