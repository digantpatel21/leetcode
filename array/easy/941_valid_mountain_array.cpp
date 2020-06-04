class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        
        int startIndex = 0;
        int endIndex = A.size()-1;
        int count = A.size();
        while(endIndex >= 0 && startIndex < A.size() && startIndex != endIndex && count > 1) {
            
            if(A[startIndex] < A[startIndex+1])
                startIndex++;
            if(A[endIndex] < A[endIndex-1])
                endIndex--;
            
            count--;
        }
        
        if(startIndex == 0 || endIndex == (A.size()-1))
            return false;

        if(startIndex == endIndex)
            return true;
        
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
        vector<int> A = stringToIntegerVector(line);
        
        bool ret = Solution().validMountainArray(A);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}