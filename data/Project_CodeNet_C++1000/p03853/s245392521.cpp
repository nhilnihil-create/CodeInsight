#include <iostream>
#include<string>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
  int H,W;scanf("%d %d",&H,&W);
  char C[H+1][W+1];
  for(int i=1;i<H+1;i++)for(int j=1;j<W+1;j++)cin>>C[i][j];
  for(int i=1;i<2*H+1;i++)
  {
    for(int j=1;j<W+1;j++)cout<<C[(i+1)/2][j];
    cout<<endl;
  }
}