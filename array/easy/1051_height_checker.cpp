class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0, max = 0;
        map<int, int> indexCount;
        vector<int> sortedArrey;
        int number = 0; 
        int count1 = 0;
        for(auto it = heights.begin(); it != heights.end(); ++it)
        {
            indexCount[*it] += 1;
        }
        
        for(auto it = indexCount.begin(); it != indexCount.end(); ++it)
        {
            while(it->second)
            {
                sortedArrey.push_back(it->first);
                it->second--;
            }
        }
        
        for(auto it = 0; it < sortedArrey.size(); ++it)
        {
            if(sortedArrey[it] != heights[it])
            {
                count++;
            }
        }
        
        return count;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> heights = stringToIntegerVector(line);
        
        int ret = Solution().heightChecker(heights);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}