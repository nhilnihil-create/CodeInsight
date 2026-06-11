#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
   string s;
   cin >> s;
   int n=s.size();
   int root=0;
   bool a=true;
   int cnt=0;
  for(int i=n-1;i>=0;i--){
    if(root==0){
      cnt++;
      if(s.at(i)=='r'){
        
        root=1;
      }
      else if(s.at(i)=='e')root=4;
      else if(s.at(i)=='m')root=5;
      else{
        a=false;
        break;
      }
    }
    else if(root==1){
        cnt++;
        if(cnt==2 && s.at(i)!='e'){
          a=false;
          break;
        }
        else if(cnt==3){
          if(s.at(i)=='s')root=2;
          else if(s.at(i)=='m')root=3;
          else{
            a=false;
            break;
          }
        }
    }
    else if(root==2){
      cnt++;
            if(cnt==4 && s.at(i)=='a');
            else if(cnt==5 && s.at(i)=='r');
            else if(cnt==6 && s.at(i)=='e'){
              root=0;
              cnt=0;
            } 
            else{
            a=false;
            break;
            }
    }
    else if(root==3){
      cnt++;
            if(cnt==4 && s.at(i)=='a');
            else if(cnt==5 && s.at(i)=='e');
            else if(cnt==6 && s.at(i)=='r');
            else if(cnt==7 && s.at(i)=='d'){
              root=0;
              cnt=0;
            }
            else{
              a=false;
              break;
            }
    }
    else if(root==4){
      cnt++;
            if(cnt==2 && s.at(i)=='s');
            else if(cnt==3 && s.at(i)=='a');
            else if(cnt==4 && s.at(i)=='r');
            else if(cnt==5 && s.at(i)=='e'){
              root=0;
              cnt=0;
            }
            else{
              a=false;
              break;
            }
    }
    else if(root==5){
      cnt++;
            if(cnt==2 && s.at(i)=='a');
            else if(cnt==3 && s.at(i)=='e');
            else if(cnt==4 && s.at(i)=='r');
            else if(cnt==5 && s.at(i)=='d'){
              root=0;
              cnt=0;
            }
            else{
              a=false;
              break;
            }
    }
  }
  if(a)cout << "YES" << endl;
  else cout << "NO" << endl;
}



    
   
