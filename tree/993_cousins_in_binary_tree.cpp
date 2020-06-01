/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isQueueContainsCousins(std::deque<TreeNode*> start, int x, int y) {
        bool isXFound = false;
        bool isYFound = false;
        for(int i = 0; i < start.size(); i++)
        {
            TreeNode* temp = start.at(i);
            if(temp->val == x)
                isXFound = true;
            
            if(temp->val == y)
                isYFound = true;
        }
        
        return isXFound && isYFound;
    } 
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        std::deque<TreeNode*> queue;
        int nextLevelStartIndex =1, previousEndIndex = 0, count = 0;
        queue.push_back(root);
        bool result = false;
        
        while(!queue.empty()) {
            
            TreeNode* currentRoot = queue.at(0);
            cout<<currentRoot->val<<endl;
            queue.pop_front();
            
            // Check if we have both childs are given node
            // if it is than return false
            
            if(currentRoot->left != NULL && currentRoot->right != NULL) {
                if(currentRoot->left->val == x || currentRoot->left->val == y) {
                    if(currentRoot->right->val == x || currentRoot->right->val == y) {
                        return false;
                    }
                }
            }
                
            if(currentRoot->left != NULL) {
                queue.push_back(currentRoot->left);
                count++;
            }
    
            if(currentRoot->right != NULL) {
                queue.push_back(currentRoot->right);
                count++;
            }
            
            previousEndIndex++;
            
            if(previousEndIndex == nextLevelStartIndex) {
                // We have traversed all one level nodes
                nextLevelStartIndex = count;
                count = 0;
                previousEndIndex = 0;
                
                if(isQueueContainsCousins(queue, x,y))
                    return true;
                //check if we have elements in current level queue
            }
        }
        return result;
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

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);
        
        bool ret = Solution().isCousins(root, x, y);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}