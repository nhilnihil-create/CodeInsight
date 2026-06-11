#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n, l;
  cin>>n>>l;
  vector<string> st;
  string input;
  for(int i=0; i<n; i++){
    cin>>input;
    st.push_back(input);
  }
  string resultString = "";
  sort(st.begin(), st.end());

  for(int i=0;i<n;i++){
    resultString += st[i];
  }

  cout<<resultString;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}
