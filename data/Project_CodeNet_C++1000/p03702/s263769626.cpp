#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int N,A,B;
  cin >> N >> A >> B;
  int H[100010];
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  sort(H,H+N);
  int isNG = 0;
  int isOK = (H[N-1]+B-1)/B;
  while(isOK-isNG>1){
    int mid = (isOK+isNG)/2;
    int need = 0;
    for(int i=0;i<N;i++){
      if(H[i]-B*mid>0){
        need+=(H[i]-B*mid+A-B-1)/(A-B);
        if(need>mid){
          isNG=mid;
          break;
        }
      }
    }
    if(isNG!=mid)
      isOK=mid;
  }
  cout << isOK << endl;
}
