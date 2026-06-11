#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	char a[200001], ar[200001];
    scanf("%s\n", a);
    int n=strlen(a);
    deque<int> dq;
    set<char> st;
    for(int i=n-1; i>=0; i--){
      st.insert(a[i]);
      if(st.size()==26){
        dq.push_front(i);
        st.clear();
      }
    }
    int k=0, l;
    vector<char> v;
    while(!dq.empty()){
      l=dq.front();
      dq.pop_front();
      set<char> st1;
      for(int i=k; i<l; i++){
        st1.insert(a[i]);
      }
      char c;
      for(int i=0; i<26; i++){
        if(st1.find((char)('a'+i))==st1.end()){
          c=(char)('a'+i);
          v.push_back((char)('a'+i));
          break;
        }
      }
      for(int i=l; i<n; i++){
        if(a[i]==c){
          k=i;
          break;
        }
      }
      k++;
    }
    st.clear();
    for(int i=k; i<n; i++){
        st.insert(a[i]);
    }
    char c1;
    for(int i=0; i<26; i++){
      if(st.find((char)('a'+i))==st.end()){
        c1=(char)('a'+i);
        v.push_back((char)('a'+i));
        break;
      }
    }
    for(int i=0; i<v.size(); i++){
      printf("%c", v[i]);
    }
    printf("\n");	
	return 0;
}
