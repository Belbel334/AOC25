#include <cstdarg>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int ans(const vector<string>& grid, int i, int j){
  int rij = grid.size();
    int col = grid[0].size();
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
    return naast;
 }

vector<pair<int, int>> toeg(const vector<string>& grid){
  int rij =grid.size();
  int col=grid[0].size();
  vector<pair<int, int>> toegang;

  for (int i = 0; i < rij; i++){
        for (int j = 0; j < col; j++){
            if (grid[i][j] == '@'){
                int naast = ans(grid, i, j);
                if (naast < 4){
                    toegang.push_back({i, j});
                }
            }
        }
    }
    return toegang;
}

int weghaal(vector<string> grid){
  int tot = 0;

  while(true){
    vector<pair<int,int>> toegn=toeg(grid);
    if (toegn.empty()){
      break;
    }
    for (auto& pos : toegn){
      grid[pos.first][pos.second] = '.';
    }
    tot += toegn.size();
    
  }
  return tot;
}

int main(){
  vector<string> grid;
  string line;

  ifstream input("input.txt");
  while(getline(input,line)){
    grid.push_back(line);
  }
  input.close();//vergeten:(
  int ant = weghaal(grid);
  cout << ant;
}

