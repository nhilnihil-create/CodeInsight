#include<bits/stdc++.h>
using namespace std;

int main()
{
  string w;cin>>w;
  vector<int> alphabets(26,0);
  for(int i=0;i<w.size();i++)alphabets[w[i]-'a']++;
  for(int i=0;i<26;i++)if(alphabets[i]%2==1){printf("No\n");return 0;}
  printf("Yes\n");
}