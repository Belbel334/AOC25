#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(int, const char*)
{
  ifstream input("input.txt");

  int c = 0;
  int pos = 1000000000+ 50;

  string line;
  while (getline(input, line))
  {
    const int rotateBy = stoi(line.substr(1));
    for (int i = 0; i < rotateBy; i++)
    {
      if (line[0] == 'L')
      {
        pos -= 1;
      }
      else
      {
        pos += 1;
      }

      //printf("Rotating %c by %d, dial now at position: %d\n", line[0], 1, pos % 100);

      if ((pos % 100) == 0)
      {
        c++;
        for (int a = 0; a < 3; a++){
          cout << a;
        }
      }
    }

  }
  std::cout << c;
}
