#include <cstdarg>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int ans(const vector<string>& grid){
  int rij=grid.size();
  int col =grid[0].size();

  int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  int toeg = 0;

  for (int i = 0; i < rij; i++){
    for (int j = 0; j < col; j++){
      if (grid[i][j] == '@'){
        int naast = 0;
                
        for (int k = 0; k < 8; k++){
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (ni >= 0 && ni < rij && nj >= 0 && nj < col){
            if (grid[ni][nj] == '@'){
              naast++;
            }
          }
        }
        if (naast < 4){
          toeg++;
        }
      }
    }
    }
  return toeg;
}

int main(){
  vector<string> grid;
  string line;

  ifstream input("input.txt");
  while(getline(input,line)){
    grid.push_back(line);
    //cout << line << endl;
  }
  //cout << grid.size();
  int ant = ans(grid);
  cout << ant << endl;
}
