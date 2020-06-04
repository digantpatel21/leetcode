class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> mapping;
        
        for(auto &x : arr) {
            if(mapping.find(x) == mapping.end() ) {
                mapping.insert(pair<int,int> (x,1)); 
            } else {
                mapping[x] = mapping[x]+1;
            }
        }
        
        for(auto &x : arr) {
            
            if(x == 0) {
                
                if(mapping[x] == 2)
                    return true;
                
                continue;
            }

            if(mapping.find(2*x ) != mapping.end() ) {
                return true;
            }
        }
        return false;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        
        bool ret = Solution().checkIfExist(arr);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}