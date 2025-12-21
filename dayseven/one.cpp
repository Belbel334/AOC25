#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

struct beam{
  long long row, col;
  long long dr, dc; 
};

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
    if (startr != -1)break;
  }

  if (startr == -1){
    cerr<<"uh oh";
    return 1;
  }


  set<tuple<long long,int,int,int>> geweest;
  queue<beam> q;
  long long tot = 0;

  q.push({startr, startCol, 1, 0});
  geweest.insert({startr, startCol, 1, 0});


  while (!q.empty()){
    beam beam = q.front();
    q.pop();

    long long newr = beam.row + beam.dr;
    long long newc = beam.col + beam.dc;

    if (newr < 0 || newr >= rows || newc < 0 || newc >= cols){
      continue;
    }

    char cell = grid[newr][newc];


    if (cell == '^'){
      tot++;

      if (newc - 1 >= 0){
        if (geweest.find({newr, newc - 1, 1, 0})== geweest.end()) {
          geweest.insert({newr, newc - 1, 1, 0});
          q.push({newr, newc - 1, 1, 0});
        }
      }

      if (newc + 1 < cols){
        if (geweest.find({newr, newc + 1, 1, 0})== geweest.end()) {
          geweest.insert({newr, newc + 1, 1, 0});
          q.push({newr, newc + 1, 1, 0});
        }
      }
    } else if (cell == '.' || cell == 'S'){
      if (geweest.find({newr, newc, beam.dr, beam.dc})== geweest.end()) {
        geweest.insert({newr, newc, beam.dr, beam.dc});
        q.push({newr, newc, beam.dr, beam.dc});
      }
    }
  }

  cout << tot << endl;

  return 0;
}
