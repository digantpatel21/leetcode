/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *sumList = NULL;
        ListNode *sumListPtr = NULL;
        int digitSum = 0;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL) {
            
            digitSum = 0;
            
            if(l1 == NULL) {
                digitSum = l2->val + carry;
                l2 = l2->next;
            } else if(l2 == NULL) {
                digitSum = l1->val + carry;
                l1 = l1->next;
            }else {
                digitSum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            
            carry = digitSum / 10 ;
            
            ListNode *newNode = new ListNode(digitSum % 10);
            
            if(sumList == NULL) {
                sumList = sumListPtr = newNode;
            } else {
                sumListPtr->next = newNode;
                sumListPtr = sumListPtr->next;
            }
        }
        
        if(carry != 0) {
            ListNode *newNode = new ListNode(carry);
            
            sumListPtr->next = newNode;
            sumListPtr = sumListPtr->next;
        }
        return sumList;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}