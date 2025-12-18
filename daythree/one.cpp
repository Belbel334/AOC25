#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int fmax(const string& line){
  //cout<<line<<endl;
  int maxj = 0;
  for(size_t i = 0; i<line.length();i++){
    for(size_t j=i+1;j<line.length();j++){
      int jolt=(line[i]-'0')*10+(line[j]-'0');
      if (jolt>maxj){
        maxj=jolt;
      }
  }}
  //cout << maxj<<endl;
  return maxj;
}

int main(){
  ifstream input("input.txt");
  if(!input.is_open()){
    return 1;
  }
  string line;
  int tot=0;
  while(getline(input,line)){
    if(line.empty()){
      continue;
    }
    int answ=fmax(line);
    tot+=answ;
  }
  input.close();
  cout << tot << endl;
  return 0;
}
