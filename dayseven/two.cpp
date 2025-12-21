#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
  ifstream input("input.txt");
  vector<string> grid;
  string line;
  while (getline(input, line)){
    if (!line.empty()){
      grid.push_back(line);
    }
  }
  input.close();
  
  if (grid.empty()){
    return 1;
  }
  
  long long rows = grid.size();
  long long cols = grid[0].size();
  long long startr = -1, startCol = -1;
  
  for (long long r = 0; r < rows; r++){  
    for (long long c = 0; c < cols; c++){
      if (grid[r][c] == 'S'){
        startr = r;
        startCol = c;
        break;
      }
    }
    if (startr != -1) break;
  }
  
  if (startr == -1){
    cerr << "uh oh" << endl;
    return 1;
  }
  
  map<pair<long long, long long>, long long> dp;
  dp[{startr, startCol}] = 1;
  
  for (long long r = startr; r < rows; r++) {
    map<pair<long long, long long>, long long> nextDp;
    
    for (auto& [pos, count] : dp) {
      if (pos.first != r) continue; 
      
      long long row = pos.first;
      long long col = pos.second;
      
      long long newr = row + 1;
      
      if (newr >= rows) {
        continue;
      }
      
      char cell = grid[newr][col];
      
      if (cell == '^') {
        if (col - 1 >= 0) {
          nextDp[{newr, col - 1}] += count;
        }
        if (col + 1 < cols) {
          nextDp[{newr, col + 1}] += count;
        }
      } else if (cell == '.' || cell == 'S') {
        nextDp[{newr, col}] += count;
      }
    }
    for (auto& [pos, count] : nextDp) {
      dp[pos] += count;
    }
  }
  
  long long total = 0;
  for (auto& [pos, count] : dp) {
    if (pos.first == rows - 1) {
      total += count;
    }
  }
  
  cout << total << endl;
  
  return 0;
}
