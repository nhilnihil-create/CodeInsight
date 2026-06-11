#include<bits/stdc++.h>
using namespace std;

#define int long long

int N;

string hoge(int n){
  string res;

  //cout<<"N = "<<N<<" n = "<<n<<endl;

  if(n <= N && to_string(n) <= to_string(N)) res = "Y";
  else if(n > N && to_string(n) > to_string(N)) res = "Y";
  else res = "N";
  // cout<<"res = "<<res<<endl;

  cout<<res<<endl;

  //string hogehoge;
  //cin>>hogehoge;

  return res;
}

bool checkt(int m){
  string ans;

  m *= 10;

  cout<<"? "<<m<<endl;
  //cout<<flush;

  ans = hoge(m);
  //cin>>ans;

  return ans == "Y";
}

void solvet(){
   int con = 0;

  for(int i = 1; con < 11;i *= 10){
    int n = i;
    string ans;

    cout<<"? "<<n<<endl;
    //cout<<flush;

    // cin>>ans;
    ans = hoge(n);

    if(ans == "Y") {
      con++;
    } else{
      break;
    }
  }

  if(con == 11) {
    for(int i = 2, j = 1; ; i *= 10, j *= 10){
      string ans;
      cout<<"? "<<i<<endl;
      cout<<flush;

      //cin>>ans;

      ans = hoge(i);
      if(ans == "Y") {

        cout<<"! "<<j<<endl;
        return ;
      }
    }
    return ;
  }
  // cout<<con<<endl;

  int l = 1, h = 10, m = 0;

  for(int i = 1; i < con; i++){
    l *= 10;
    h *= 10;
  }

  while(l + 1< h){
    m = (l + h)/2;

    if(!checkt(m)){
      l = m;
    } else {
      h = m;
    }
  }

  cout<<"! "<<h<<endl;
  cout<<flush;
}


void test(){

  while(true){
    cin>>N;

    solvet();

    while(true){
      int x;
      cin>>x;
      cout<<hoge(x)<<endl;
    }
  }
}


bool check(int m){
  string ans;

  m *= 10;

  cout<<"? "<<m<<endl;
  cout<<flush;

  cin>>ans;

  return ans == "Y";
}





void solve(){
   int con = 0;

  for(int i = 1;con < 11 ;i *= 10){
    int n = i;
    string ans;

    cout<<"? "<<n<<endl;
    cout<<flush;

    cin>>ans;

    if(ans == "Y") {
      con++;
    } else if(ans == "N"){
      break;
    }
  }
  if(con == 11) {
    for(int i = 2, j = 1; ; i *= 10, j *= 10){
      string ans;
      cout<<"? "<<i<<endl;
      cout<<flush;

      cin>>ans;

      if(ans == "Y") {

        cout<<"! "<<j<<endl;
        return ;
      }
    }
    return ;
  }

  int l = 1, h = 10, m = 0;

  for(int i = 1; i < con; i++){
    l *= 10;
    h *= 10;
  }

  while(l + 1< h){
    m = (l + h)/2;

    if(!check(m)){
      l = m;
    } else {
      h = m;
    }
  }

  cout<<"! "<<h<<endl;
  cout<<flush;
}



signed main(){

  // test();

  solve();

  return 0;
}
