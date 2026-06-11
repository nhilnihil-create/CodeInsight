#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
speed_up;
string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int l1, l2, l3;
  l1 = s1.size();
  l2 = s2.size();
  l3 = s3.size();
  int cnt1, cnt2, cnt3;
  cnt1 = cnt2 = cnt3 = 0;
  char t = 'A';
  while(true) {
    if(t == 'A' && cnt1 == l1 || t == 'B' && cnt2 == l2 || t == 'C' && cnt3 == l3) break;
    if(t == 'A') {
      if(s1[cnt1] == 'b') t = 'B';
      else if(s1[cnt1] == 'c') t = 'C';
      ++cnt1;
    } else if(t == 'B') {
      if(s2[cnt2] == 'a') t = 'A';
      else if(s2[cnt2] == 'c') t = 'C';
      ++cnt2;
    } else {
      if(s3[cnt3] == 'a') t = 'A';
      else if(s3[cnt3] == 'b') t = 'B';
      ++cnt3;
    }
  }
 
  cout << t << endl;
 
  return 0;
}