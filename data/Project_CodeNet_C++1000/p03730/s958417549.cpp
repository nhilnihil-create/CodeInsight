#include <iostream>
#include <set>
using namespace std;
int main(){
  int a,b,c; cin >> a >> b >> c;
  set<int> st;
  for (int i = 0; i <= b; i++)
    st.insert((a*i)%b);
  printf("%s\n",(st.find(c)!=st.end()) ? "YES" : "NO");
  return 0;
}