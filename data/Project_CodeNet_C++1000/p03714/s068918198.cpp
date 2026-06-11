#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define ll long long

int main () {
  ll n;
  cin >> n;
  ll a[3 * n];
  ll l_sum[3 * n];
  ll r_sum[3 * n];
  for (ll i = 0; i < 3 * n; i++) {
    l_sum[i] = 0;
    r_sum[i] = 0;    
  }
  for (int i = 0; i < n * 3; i++) {
    cin >> a[i];     
  }  
  priority_queue<ll, vector<ll>, greater<ll> > box;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      l_sum[i] = a[i];  
    }  
    else {
      l_sum[i] = l_sum[i - 1] + a[i];  
    }
    box.push(a[i]);
  }
  for (int i = n; i < 2 * n; i++) {
    ll sub = box.top();
    if (a[i] > sub) {
      l_sum[i] = l_sum[i - 1] + a[i] - sub;  
      box.pop();
      box.push(a[i]);
    }  
    else {
      l_sum[i] = l_sum[i - 1];  
    }
  }
  priority_queue<ll> box2;
  for (int i = 0; i < n; i++) {
    int j = 3 * n - 1 - i;
    if (j == 3 * n - 1) {
      r_sum[i] = a[j];    
    }
    else {
      r_sum[i] = r_sum[i - 1] + a[j]; 
    }  
    box2.push(a[j]);
  }
  for (int i = n; i < 2 * n; i++) {
    int j = 3 * n - 1 - i;
    ll sub = box2.top();
    if (a[j] < sub) {
      r_sum[i] = r_sum[i - 1] + a[j] - sub;
      box2.pop();
      box2.push(a[j]); 
    }  
    else {
      r_sum[i] = r_sum[i - 1];  
    }
  }
  ll max;
  for (int i = 0; i <= n; i++) {
    int left = n - 1 + i;
    int right = 2 * n - i - 1;
    // cout << l_sum[left] << " " << r_sum[right] << endl;
    if (i == 0) {
      max = l_sum[left] - r_sum[right];  
    }    
    else {
      if (max <= l_sum[left] - r_sum[right]) {
        max = l_sum[left] - r_sum[right];  
      }  
    }
  }
  cout << max << endl;
}