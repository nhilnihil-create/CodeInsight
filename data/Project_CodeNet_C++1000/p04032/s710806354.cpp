#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>   
#include<limits.h>
#include<list>
#include <array>
using namespace std;
#define i64  long long
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807
#define INF I64_MAX
#define MOD 1000000007



void solve(void)
{
  string str;
  cin>>str;
  int check = 0;
  int check_index;
  if(str.size () == 2)
  {
    if(str[0]==str[1])
    {
      cout<<1<<" "<<2<<endl;
      return;
    }
    else
    {
      cout<<-1<<" "<<-1<<endl;
      return;
    }
    
  }

  for (int i = 0; i < str.size()-1; i++)
  {
    if(str[i] == str[i+1]) {check = 1;
    check_index = i;}
  }

  for (int i = 0; i < str.size()-2; i++)
  {
    if(str[i] == str[i+2]) {check = 1;
    check_index = i;}
  }

  if(check==0)
  {
    cout<<-1<<" "<<-1<<endl;
  }
  else
  {
    cout<<check_index+1<<" "<<check_index+3<<endl;
    cout<<endl;    
  }
  
  
  
  
  return;
}



int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // std::cout << std::fixed;
  // std::cout << std::setprecision(8);

  solve();

 
  return 0;
}