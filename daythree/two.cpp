#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

long long calcJ(const string& line, const vector<int>& wisk){
  long long jolt=0;
  for (int i:wisk){
    jolt=jolt*10+(line[i]-'0');
  }
  return jolt;
}

long long fmax(const string& line){
  //cout<<line<<endl;
  long long maxj = 0;
  vector<int> wiskunde(12);
  for(int i=0; i<12; i++){
    wiskunde[i] = i;
  }
  function<void(int,int)> genCom=[&](int start,int ver){
    if (ver==12){
      long long jolt=calcJ(line, wiskunde);
      if (jolt>maxj){
        maxj=jolt;
      }
      return;
    }
    for(int i =start; i<=line.length()-(12-ver);i++){
      wiskunde[ver]=i;
      genCom(i+1,ver+1);
    }
  };
  
  genCom(0,0);
  //cout << maxj<<endl;
  return maxj;
}

int main(){
  ifstream input("input.txt");
  if(!input.is_open()){
    return 1;
  }
  string line;
  long long tot=0;
  while(getline(input,line)){
    if(line.empty()){
      continue;
    }
    long long answ=fmax(line);
    tot+=answ;
  }
  input.close();
  cout << tot << endl;
  return 0;
}
