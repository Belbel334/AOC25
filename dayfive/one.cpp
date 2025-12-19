#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct r{
  long long start;
  long long end;
};
bool fvers(long long id, const std::vector<r>& range){
  for (const auto& range:range){
    if (id>=range.start&&id<=range.end){
      return true;
    }
  }
  return false;
}
int main(){
  ifstream input("input.txt");
  vector<r> vers;
  vector<long long> ids;
  string line;
  bool a = true;
  int aantalvers=0;
  
  while(getline(input,line)){
    if(line.empty()){
      a = false;
      continue;
    }
    if(a){
      size_t streep = line.find('-');
      if(streep!=string::npos){
        long long start = stoll(line.substr(0,streep));
        long long end = stoll(line.substr(streep+1));
        vers.push_back({start,end});
      }
    }else{
      ids.push_back(stoll(line));
    }
  }
  
  input.close();
  
  for(long long id:ids){
    if(fvers(id, vers)){
      aantalvers++;
    }
  }
  
  cout<<aantalvers<<endl;
  
  return 0;
}
