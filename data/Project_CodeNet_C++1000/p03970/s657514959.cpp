    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
      //int w,h,tmp;
      string s,t;
      cin >> s;
      int ans = 0;
      t = "CODEFESTIVAL2016";
      for(int i=0; i<s.size(); i++)
        if(s.at(i)==t.at(i)) ans++;
     
      cout << 16-ans << endl;
    }