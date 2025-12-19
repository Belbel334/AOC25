#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct r{
  long long start;
  long long end;
};
int main(){
  ifstream input("input.txt");
  vector<r> vers;
  vector<long long> ids;
  string line;
  long long aantalvers=0;
  vector<r> ant; 

  while(getline(input,line)){
    if(line.empty()){
      break;
    }
    size_t streep = line.find('-');
    if(streep!=string::npos){
      long long start=stoll(line.substr(0,streep));
      long long end=stoll(line.substr(streep+1));
      vers.push_back({start,end});
    }
  }
  
  input.close();
  sort(vers.begin(), vers.end(), [](const r& a, const r& b){
      return a.start<b.start;
  }); 
  
  for(const auto& ran : vers){
    if(ant.empty()||ant.back().end+1<ran.start){
      ant.push_back(ran);
    }else{
      ant.back().end=max(ant.back().end,ran.end);
    }
  }
  for(const auto& ran: ant){
    aantalvers+=(ran.end-ran.start+1);
  }
  
  cout<<aantalvers<<endl;
  
  return 0;
}

