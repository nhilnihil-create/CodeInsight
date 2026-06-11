#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int a[n], reg[9]={};
  
  for(int i=0; i<n; i++) {
    cin >> a[i];
    if(a[i]<400) reg[0]=1;
    else if(a[i]<800) reg[1]=1;
    else if(a[i]<1200) reg[2]=1;
    else if(a[i]<1600) reg[3]=1;
    else if(a[i]<2000) reg[4]=1;
    else if(a[i]<2400) reg[5]=1;
    else if(a[i]<2800) reg[6]=1;
    else if(a[i]<3200) reg[7]=1;
    else reg[8]++;
  }

  int min_reg, max_reg;
  min_reg = max(accumulate(reg,reg+8,0),1);
  max_reg = accumulate(reg,reg+9,0);

  cout << min_reg << " " << max_reg << endl;
  return 0;
}