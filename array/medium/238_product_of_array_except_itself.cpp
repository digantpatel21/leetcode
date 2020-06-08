class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> productArr(nums.size(), 1);
        
        int index = 0;
        int endIndex = nums.size()-1;
        
        int previousProduct = 1;
        int nextProduct = 1;
        
        while(index < nums.size()) {
            
            productArr[index] *= previousProduct;
            productArr[endIndex-index] *= nextProduct;
            
            previousProduct *= nums[index];
            nextProduct *= nums[endIndex-index];
            
            index++;
        }
        
        
        return productArr;
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
        vector<int> nums = stringToIntegerVector(line);
        
        vector<int> ret = Solution().productExceptSelf(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}