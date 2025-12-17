
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isInvalidId(long long n) {
    string s = to_string(n);
    int length = s.length();
    
    if (length % 2 != 0) {
        return false;
    }
    
    int midden = length / 2;
    string linkerhelft = s.substr(0, midden);
    string rechthalf = s.substr(midden);
    
    return linkerhelft == rechthalf;
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
    
    cout << tot;
    
    return 0;
}

