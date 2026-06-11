#include <iostream>
#include <string>

using namespace std;

int main(){

  string s;
  int appear_cnt[26][2]={0};
  int over_half;

  int char_num = 0;
  const int char_base = 'a';

  int a = 0, b = 0;

  cin >> s;

  int s_len=s.size();
  over_half = s_len / 2 + 1;

  for (int i = 0; i < s_len; i++)
  {
    char_num = (char)s[i] - char_base;
    
    if (appear_cnt[char_num][0]==0)
    {
      appear_cnt[char_num][1] = -3;
    }
    appear_cnt[char_num][0]++;

    if (i-appear_cnt[char_num][1]<=2) {
      a = i - 1;
      b = i + 1;
      appear_cnt[char_num][1] = i;      
      break;
    }
    else
    {
      appear_cnt[char_num][1] = i;
    }
  }

  if (a==0 && b!=0)
  {
    a = 1;
    b = appear_cnt[char_num][1] + 1;
  }

  if (a==0 || b==0)
  {
    cout << -1 << " " << " " << -1 << endl;
  } else 
  {
    //cout << s.substr(a, b-a+1) << endl;
    cout << a << " " << " " << b << endl;
  }

  return 0;
}