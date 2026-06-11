#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> cl(8);
  int cnt = 0, cnt2 = 0;
  for(int i=0; i<n; ++i) cin >> a[i];
  for(int i=0; i<n; ++i){
    if(1<=a[i] && a[i]<=399) cl[0]=true;

    if(400<=a[i] && a[i]<=799) cl[1]=true;

    if(800<=a[i] && a[i]<=1199) cl[2]=true;;

    if(1200<=a[i] && a[i]<=1599) cl[3]=true;

    if(1600<=a[i] && a[i]<=1999) cl[4]=true;

    if(2000<=a[i] && a[i]<=2399) cl[5]=true;

    if(2400<=a[i] && a[i]<=2799) cl[6]=true;

    if(2800<=a[i] && a[i]<=3199) cl[7]=true;

    else if(3200<=a[i]) ++cnt2;
  }
  if(cnt2==n){
    cout << 1 << " " << n;
    return 0;
  }
  for(int i=0; i<8; ++i){
    if(cl[i]==true) cnt++;
  }
  cout << cnt << " " << cnt+cnt2 << endl;
  return 0;
}