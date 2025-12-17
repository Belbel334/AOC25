#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isInvalidId(long long n) {
    string s = to_string(n);
    int lengte = s.length();
    
    if (lengte==1){
      return false;
    }

    for (int patLen = 1; patLen <= lengte / 2; patLen++) {
        if (lengte % patLen == 0) {
            string patr = s.substr(0, patLen);
            bool matches = true;
            
            int numRepeats = lengte / patLen;
            for (int rep = 1; rep < numRepeats; rep++) {
                string deel = s.substr(rep * patLen, patLen);
                if (deel != patr) {
                    matches = false;
                    break;
                }
            }
            
            if (matches && numRepeats >= 2) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ifstream input("input.txt");
    
    string line;
    getline(input, line);
    input.close();
    
    vector<pair<long long, long long>> getalletjes;
    stringstream ss(line);
    string getalstr;
    
    while (getline(ss, getalstr, ',')) {
        size_t dashPos = getalstr.find('-', 1);
        if (dashPos != string::npos) {
            string startStr = getalstr.substr(0, dashPos);
            string endStr = getalstr.substr(dashPos + 1);
            
            long long start = stoll(startStr);
            long long end = stoll(endStr);
            getalletjes.push_back({start, end});
        }
    }
    
    long long tot = 0;
    vector<long long> invalidIds;
    
    for (const auto& r : getalletjes) {
        long long start = r.first;
        long long end = r.second;
        
        for (long long num = start; num <= end; num++) {
            if (isInvalidId(num)) {
                invalidIds.push_back(num);
                tot += num;
            }
        }
    }
        

    cout << tot<<endl;
    
    return 0;
}
