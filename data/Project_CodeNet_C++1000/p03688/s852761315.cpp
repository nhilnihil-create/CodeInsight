#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;

int in[N];
void solve() {
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;++i) {
      scanf("%d",&in[i]);
   }
   sort(in,in+n);
   if(in[n-1]- in[0] >1) {
      printf("No\n");
      return;
   }
   if(in[n-1]== in[0]) {
      int x = in[0];
      if(x+1==n || n/x>1) {
         printf("Yes\n");
      } else {
         printf("No\n");
      }
   } else {
      int cc = 0;
      for(int i=0;i<n;++i) {
         if(in[i]==in[0]) {
            ++cc;
         }
      }
      int k = n - (cc);
      if(k==1) {
         printf("No\n");
         return;
      }
      int t = k/2;
      if(cc >in[0]) {
         printf("No\n");
         return;
      }
      if(cc<=in[0] && in[n-1] <= cc + k/2){
         printf("Yes\n");
         return;
      }
      printf("No\n");
   }
}
int main() {
   //freopen("input.txt","r",stdin);
   solve();
}