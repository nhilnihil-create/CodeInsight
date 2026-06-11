#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  	int N, count, Ans=1, Max=0;
    cin >> N;
    for (int i=1; i<=N; i++){
    	 count=0;
         int k=i;
      while (true){
         if (k%2==0){
         	count++;
         	k/=2;
         }
         else if (k%2==1){
         		 if (count>Max){
                 	Max = count;
                    Ans = i;
                 }
                 break;
         }
      }
    }
    cout << Ans << endl;
}
