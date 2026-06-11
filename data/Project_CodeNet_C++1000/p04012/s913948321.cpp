//*Here I go out to sea again
//*The sunshine fills my hair
//*And dreams hang in the air

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[26]={0};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
      a[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
      if(a[i]%2!=0){
        cout<<"No"<<"\n";
        return 0;
      }
    }
    cout<<"Yes"<<"\n";

    return 0;
}
