/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int lengthA = 1;
        int lengthB = 1;

        while(temp1->next != NULL) {
            temp1 = temp1->next;
            lengthA++;
        }

        while(temp2->next != NULL) {
            temp2 = temp2->next;
            lengthB++;
        }
        
        if(temp1 != temp2)
            return NULL;
        
        temp1 = headA;
        temp2 = headB;
        
        // Now we have end node common
        // means both list merged
        
        int diff  = abs(lengthB-lengthA);
        
        if(lengthA > lengthB) {
            
            while(diff > 0) {
                temp1 = temp1->next;
                diff--;
            }
            
        } else {
            while(diff > 0) {
                temp2 = temp2->next;
                diff--;
            }    
        }
        
        while(temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return temp1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int intersectVal = stringToInteger(line);
        getline(cin, line);
        ListNode* listA = stringToListNode(line);
        getline(cin, line);
        ListNode* listB = stringToListNode(line);
        getline(cin, line);
        int skipA = stringToInteger(line);
        getline(cin, line);
        int skipB = stringToInteger(line);
        
        ListNode* ret = Solution().getIntersectionNode(intersectVal, listA, listB, skipA, skipB);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}