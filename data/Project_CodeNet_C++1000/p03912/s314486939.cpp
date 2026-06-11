#include<iostream>
#include<map>
#include<vector>

int main(){
  int n,m;
  std::cin >> n >> m;
  std::vector<int> x(n);
  std::map<int,std::map<int,int> > units;
  std::map<int,std::map<int,int> > buf;
  std::vector<int> oddExist(m);
  for(int i=0;i<n;i++){
    std::cin >> x[i];
    if(buf[x[i]%m].find(x[i])==buf[x[i]%m].end()){
      if(units[x[i]%m].find(x[i])!=units[x[i]%m].end()){
        buf[x[i]%m][x[i]] = 2;
        units[x[i]%m].erase(x[i]);
      }else{
        units[x[i]%m][x[i]] = 1;
      }
    }else{
      buf[x[i]%m][x[i]]++;
    }
  }
  /*for(int i=0;i<m;i++){
    std::cout << "[" << i << "]";
    auto u = buf[i];
    for(auto it=u.begin();it!=u.end();it++){
      std::cout << "(" << it->first << "," << it->second << ")";
    }
    std::cout << std::endl;
  }*/
  int count = 0;
  for(int i=0;i<m;i++){
    if(units.find(i)==units.end())continue;
    auto &u = units[i];
    if(i==0 || i*2==m){
      count += u.size()/2;
      if(u.size()%2==1){
        buf[i][0]++;
      }
    }else if(units.find(m-i)!=units.end()){
      auto &v = units[m-i];
      count += std::min(u.size(),v.size());
      if(u.size() > v.size()){
        buf[i][0]+=u.size()-v.size();
      }else if(u.size() < v.size()){
        buf[m-i][0]+=v.size()-u.size();
      }
      units.erase(i);
      units.erase(m-i);
    }else{
      buf[i][0]+=u.size();
    }
  }
  for(int i=0;i<m;i++){
    oddExist[i] = false;
    if(buf.find(i)==buf.end())continue;
    auto &u = buf[i];
    if(u.find(0)!=u.end()){
      oddExist[i] = true;
      continue;
    }
    for(auto it=u.begin();it!=u.end();it++){
      if(it->second%2==1){
        oddExist[i] = true;
        break;
      }
    }
  }
  /*std::cout << count << std::endl;
  for(int i=0;i<m;i++){
    std::cout << "[" << i << "]";
    auto u = buf[i];
    for(auto it=u.begin();it!=u.end();it++){
      std::cout << "(" << it->first << "," << it->second << ")";
    }
    std::cout << std::endl;
  }*/
  while(1){
    bool update = false;
    for(auto pt=buf.begin();pt!=buf.end();pt++){
      int i = pt->first;
      auto &u = pt->second;
      if(i==0 || i*2==m){
        if(oddExist[i])for(auto it=u.begin();it!=u.end();it++){
          if(it->second%2==1 || it->first==0){
            bool po = false;
            for(auto jt=it;jt!=u.end();jt++){
              if(it!=jt && (jt->second%2==1 || jt->first==0)){
                it->second--;
                jt->second--;
                count++;
                update = po = true;
                if(jt->second==0){
                  u.erase(jt);
                }
                break;
              }
            }
            if(!po){
              for(auto jt=u.begin();jt!=u.end();jt++){
                if(it==jt)continue;
                it->second--;
                jt->second--;
                count++;
                update = po = true;
                if(jt->second==0){
                  u.erase(jt);
                }
                break;
              }
            }
            if(po){
              if(it->second==0){
                it = u.erase(it);
                if(it==u.end())break;
                else it--;
              }
            }
          }
        }
      }else{
        int j = m-i;
        if(buf.find(j)==buf.end())continue;
        auto &v = buf[j];
        if(oddExist[i])for(auto it=u.begin();it!=u.end();it++){
          if(it->second%2==1 || it->first==0){
            bool po = false;
            int cnt = 0;
            if(oddExist[j])for(auto jt=v.begin();jt!=v.end();jt++){
              if(cnt++ > 100)break;
              if(jt->second%2==1 || jt->first==0){
                it->second--;
                jt->second--;
                count++;
                update = po = true;
                if(jt->second==0){
                  v.erase(jt);
                }
                break;
              }
            }
            if(!po){
              for(auto jt=v.begin();jt!=v.end();jt++){
                it->second--;
                jt->second--;
                count++;
                update = po = true;
                if(jt->second==0){
                  v.erase(jt);
                }else oddExist[j] = true;
                break;
              }
            }
            if(po){
              if(it->second==0){
                it = u.erase(it);
                if(it==u.end())break;
                else it--;
              }
            }
          }
        }
      }
      if(u.size()==0){
        pt = buf.erase(pt);
        if(pt==buf.end())break;
        else pt--;
      }
    }
    if(!update)break;
  }
  for(auto pt=buf.begin();pt!=buf.end();pt++){
    int i = pt->first;
    auto &u = pt->second;
    for(auto it=u.begin();it!=u.end();it++){
      if(it->first!=0)count += it->second/2;
    }
  }
  std::cout << count << std::endl;
  return 0;
}