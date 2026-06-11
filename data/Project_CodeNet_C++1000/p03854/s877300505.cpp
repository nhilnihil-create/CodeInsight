#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <stdio.h>
#include <unistd.h>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define drep(i, n) for(int i = n - 1; i >= 0; i--)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define PI 3.14159265359

const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const int mod = 1000000007;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

string s;
int solve(int index) {
  if (s.size() == index) {
    return 1;
  }
  int flag = 0;
  if (s.size() >= index + 5) {
    string tmp = s.substr(index, 5);
    int flag = 0;
    if (tmp == "dream") flag = solve(index + 5);
    else if (tmp == "erase") flag = solve(index + 5);
    if (flag == 1) return 1;
  }
  if (s.size() >= index + 6) {
    string tmp = s.substr(index, 6);
    if (tmp == "eraser") flag = solve(index + 6);
    if (flag == 1) return 1;
  }
  if (s.size() >= index + 5) {
    string tmp = s.substr(index, 7);
    if (tmp == "dreamer") flag = solve(index + 7);
    if (flag == 1) return 1;
  }
  return 0;
}

int main() {
  cin >> s;
  if (solve(0) == 1) YES;
  else NO;


  return 0;
}

