#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
#define ll long long
#define REP(a,b) for(ll a=0; a<b; a++)
using namespace std;

ll mx[100005];
ll mn[100005];
priority_queue <ll, vector<ll>, greater<ll>> front;
vector <ll> middle;
priority_queue <ll> back;
ll sumf = 0;
ll sumb = 0;

int main() {
  ll N;
  scanf("%lld", &N);
  REP(i, N){
    ll temp;
    scanf("%lld", &temp);
    front.push(temp);
    sumf += temp;
  }
  REP(i, N){
    ll temp;
    scanf("%lld", &temp);
    middle.push_back(temp);
  }
  REP(i, N){
    ll temp;
    scanf("%lld", &temp);
    back.push(temp);
    sumb += temp;
  }
  ll mxm = LLONG_MIN;
  int l = 0;
  while(l < N){
    mx[l] = sumf;
    if(middle[l] - front.top() > 0){
      sumf -= front.top();
      sumf += middle[l];
      front.pop();
      front.push(middle[l]);
    }
    l++;
  }
  mx[l] = sumf;
  int r = N;
  mn[r] = sumb;
  r--;
  while(r >= 0){
    if(back.top() - middle[r] > 0){
      sumb -= back.top();
      sumb += middle[r];
      back.pop();
      back.push(middle[r]);
    }
    mn[r] = sumb;
    r--;
  }
  REP(i, N+1){
    mxm = max(mxm, mx[i]-mn[i]);
  }
  cout << mxm << endl;
}