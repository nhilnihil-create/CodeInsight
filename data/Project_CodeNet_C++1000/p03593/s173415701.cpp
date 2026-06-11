#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#define invrep(i,n) for(int64_t i=n-1;i >= 0;i--)
#define _GLIBCXX_DEBUG
using namespace std;

//////全探索したいときに開けよ////////
vector<vector<int>> fspattern;
vector<int> fspattern_draft;
int fspcnt = 0;

void setfspattern_core(int floor,int number,int degree){
  if(floor==degree){
    fspattern.at(fspcnt) = fspattern_draft;
    fspcnt++;
  }else{
    rep(i,number){
      fspattern_draft.at(floor) = i;
      setfspattern_core(floor+1,number,degree);
    }
  }
}

void setfspattern(int number,int degree){
  fspcnt = 0;
  int64_t array_num = 1;
  rep(i,degree){
    array_num *= number;
  }
  fspattern = vector<vector<int>>(array_num,vector<int>(degree));
  fspattern_draft = vector<int>(degree);
  setfspattern_core(0,number,degree);
}

//////nCrのmodを求めたいときに開けよ/////////
int64_t univMod = 1000000007;
int64_t factnum = 200000; //変更すること
vector<int64_t> modfact(factnum);
vector<int64_t> modinvfact(factnum);

void setmodfact(){
  for(int i=0;i<factnum;i++){
    if(i == 0){
      modfact.at(i) = 1;
    }else{
      modfact.at(i) = (modfact.at(i-1)*i)%univMod;
    }
  }
}

int64_t modpower(int64_t a,int64_t n){
  int64_t res = 1;
  while(n != 0){
    if(n & 1){
      res = (res * a) % univMod;
    }
    a = (a*a) % univMod;
    n = n >> 1;
  }
  return res;
}

int64_t modinverse(int64_t n){
	return modpower(n,univMod-2);
}

void setmodinvfact(){
  for(int i=0;i<factnum;i++){
    if(i==0){
      modinvfact.at(i) = 1;
    }else{
      modinvfact.at(i) = modpower(modfact.at(i),univMod-2);
    }
  }
}

int64_t modcomb(int64_t n,int64_t r){
  return (((modfact.at(n)*modinvfact.at(n-r))%univMod)*modinvfact.at(r))%univMod;
}

int64_t modperm(int64_t n,int64_t r){
  return (modfact.at(n)*modinvfact.at(n-r))%univMod;
}

int64_t calcGCD(int64_t a,int64_t b){
	int64_t p = a;
	int64_t q = b;
	int64_t c = a%b;
	while(c != 0){
		p = q;
		q = c;
		c = p%q;
	}
	return q;
}


int main(){
  int64_t h,w;
  cin >> h >> w;
  vector<int64_t> alph(26);
  rep(i,h){
    rep(j,w){
      char k;
      cin >> k;
      alph[k - 'a']++;
    }
  }
  int64_t cnt2 = 0;
  int64_t odd = 0;
  rep(i,26){
    if(alph[i] % 2 == 1){
      odd++;
      alph[i]--;
    }
    if(alph[i] % 4 != 0){
      cnt2++;
    }
  }
  if(h % 2 == 0 && w % 2 == 0){
    if(odd == 0 && cnt2 == 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else if(h % 2 != 0 && w % 2 == 0){
    if(odd == 0 && cnt2 <= w/2){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else if(w % 2 != 0 && h % 2 == 0){
    if(odd == 0 && cnt2 <= h/2){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    if(odd == 1 && cnt2 <= ((w-1)/2)+((h-1)/2)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }

    
    
    
      
}