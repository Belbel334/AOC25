#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long ant(const vector<string>& lines){
  if(lines.empty()){
    cout<<"uh oh";
    return 0;
  }
  size_t breed = 0;
  for(const auto& line : lines){
    breed = max(breed, line.length());
  }
  
  vector<string> fix;
  long long a=0;
  
  for(const auto& line : lines){
    string s=line;
    s.resize(breed, ' ');
    fix.push_back(s);
  }
  
  vector<vector<int>>problems;
  vector<int>curproblem;
  
  for(size_t col=0;col<breed;col++){
    bool content=false;
    for (const auto& line:fix){
      if (line[col] != ' ') {
        content = true;
        break;
      }
    }
    if(content){
      curproblem.push_back(col);
    }else{
      if(!curproblem.empty()){
        problems.push_back(curproblem);
        curproblem.clear();
      }
    }
  }
  
  if(!curproblem.empty()){
    problems.push_back(curproblem);
  }
  
  vector<long long> antwrdn;
  
  for(const auto& problcol:problems){
    vector<string> data;
    for(const auto& line:fix){
      string rdata;
      for(int col:problcol){
        rdata+=line[col];
      }
      size_t start=rdata.find_first_not_of(' ');
      size_t end=rdata.find_last_not_of(' ');
      if(start!=string::npos&&end!=string::npos){
        rdata=rdata.substr(start,end-start+1);
        if(!rdata.empty()){
          data.push_back(rdata);
        }
      }
    }
    
    if(data.empty())continue;
    
    string op=data.back();
    data.pop_back();
    
    vector<long long> nums;
    long long tot;
    
    for (const auto& numStr:data){
      try {
        nums.push_back(stoll(numStr));
      } catch (...) {
        continue;
      }
    }
    
    if (nums.empty())continue;
    
    if (op=="+"){
      tot=0;
      for(long long num:nums){
        tot+=num;
      }
    }else if(op=="*"){
      tot=1;
      for(long long num:nums){
        tot*=num;
      }
    }else{
      continue;
    }
    
    antwrdn.push_back(tot);
  } 
  
  for (long long r:antwrdn){
    a+=r;
  }
  
  return a;
}

int main(){
  ifstream input("input.txt");
  vector<string> lines;
  string line;
  
  while(getline(input,line)){
    lines.push_back(line);
  }
  
  input.close();
  
  long long j = ant(lines);
  cout << j << endl;
  
  return 0;
}
