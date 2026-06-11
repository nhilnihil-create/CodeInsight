#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  long long p;
  int cmpflg,allflg;
  
  cin >> s;

  p=s.length();
  allflg=0;
  while (1)
  {
    	cmpflg=0;
    	if (p>=7)
        {
	    	if (strncmp(s.substr(p-7,7).c_str(),"dreamer",7)==0)
            {
              ++cmpflg;
    	      p -= 7;
            }
        }
    	
    	if (p>=5)
        {
          if (strncmp(s.substr(p-5,5).c_str(),"dream",5)==0)
            {
              ++cmpflg;
    	      p -= 5;
            }
        }
    
    	if (p>=6)
        {
    		if (strncmp(s.substr(p-6,6).c_str(),"eraser",6)==0)
            {
              ++cmpflg;
    	      p -= 6;
            }
        }
    
    	if (p>=5)
        {
    		if (strncmp(s.substr(p-5,5).c_str(),"erase",5)==0)
            {
              ++cmpflg;
    	      p -= 5;
            }
        }
    	
	    if (cmpflg==0)
        {	//不一致
          allflg = -1;
          break;
        }
    	
    	//先頭チェック
    	if (p<=0)
        {
          break;
        }
  }

  if (allflg==0)
	  cout << "YES" << endl;
  else
	  cout << "NO" << endl;
}
