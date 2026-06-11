#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N;
vector<int> a;

bool judge(){
    sort(a.begin(),a.end());
    int diam=a[N-1];
    int mia=0;
    if(diam%2) mia=(diam+1)/2;
    else mia=diam/2;

    if(a[N-1]!=diam||a[0]!=mia) return false;
    int numOfMia=0;
    for(int i=0;i<N;i++){
        if(a[i]!=mia) break;
        numOfMia++;
    }
    if(diam%2&&numOfMia!=2) return false;
    if(diam%2==0&&numOfMia!=1) return false;

    int num[N+10]={};
    for(int i=0;i<N;i++) num[a[i]]++;
    for(int i=mia+1;i<=diam;i++){
        if(num[i]<2) return false;
    }

    return true;
}

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
      int x;
      cin>>x;
      a.push_back(x);
  }
  
  if(judge()) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;

  return 0;
}
