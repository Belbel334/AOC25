#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long ant(const vector<string>& lines){
  if(lines.empty()){
    cout<<"uh oh"<<endl;
    return 0;
  }
  
  size_t breed = 0;
  for(const auto& line : lines){
    breed = max(breed, line.length()); 
  }
  
  vector<string> fix;
  
  for(const auto& line : lines){
    string s=line;
    s.resize(breed, ' ');
    fix.push_back(s);
  }
  
  vector<vector<int>> problems;
  vector<int> curproblem;
  
  for(size_t col=0;col<breed;col++){
    bool content=false;
    for (const auto& line:fix) {
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
    string op = "";
    int lastRow = fix.size() - 1;
    for(int col : problcol){
      char c = fix[lastRow][col];
      if(c == '+' || c == '*'){
        op = string(1, c);
        break;
      }
    }
    
    if(op.empty())continue;
    
    vector<long long> nums;
    
    for(int i = problcol.size() - 1; i >= 0; i--){
      int col = problcol[i];
      string numStr = "";
      
      for(int row = 0; row < (int)fix.size() - 1; row++){
        char c = fix[row][col];
        if(c != ' '){
          numStr += c;
        }
      }
      
      if(numStr.empty())continue;
      
      bool isNumber = true;
      for(char ch : numStr){
        if(!isdigit(ch)){
          isNumber = false;
          break;
        }
      }
      
      if(isNumber){
        try {
          long long num = stoll(numStr);
          nums.push_back(num);
        } catch (...){
          continue;
        }
      }
    }
    
    if(nums.empty())continue;
    
    long long tot;
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
  
  long long a = 0;
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
