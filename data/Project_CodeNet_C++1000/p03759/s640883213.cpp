#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int main(){
vector<int> v(3);
for(int i=0;i<3;i++)cin>>v[i];
sort(v.begin(),v.end());
if(v[1]*2==v[0]+v[2])cout<<"YES";
else cout<<"NO";

}