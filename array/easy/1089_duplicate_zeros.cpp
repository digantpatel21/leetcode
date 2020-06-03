class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int numberOfZeros = 0;
        int vectorSize = arr.size();

        for(auto &x : arr) {
            numberOfZeros = (x== 0) ? numberOfZeros+1 : numberOfZeros;
        }
        
        arr.resize(vectorSize+numberOfZeros);
        
        for(int index = arr.size()-1; index >= 0; index--) {
          
            arr[index] = arr[index - numberOfZeros];
            
            if(arr[index-numberOfZeros] == 0) {
                arr[index-1] = 0;
                numberOfZeros--;
                index--;
            }
        }
        
        arr.resize(vectorSize);
        
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);
        
        Solution().duplicateZeros(arr);

        string out = integerVectorToString(arr);
        cout << out << endl;
    }
    return 0;
}