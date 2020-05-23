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
public:
    int findBottomLeftValue(TreeNode* root) {
        deque<TreeNode*> levelOrder;
        bool isLeftNodeAccessed = false;
        levelOrder.push_back(root);
        levelOrder.push_back(NULL);
        int leftVal = 0;
        while(!levelOrder.empty()) {
            
            TreeNode* temp = levelOrder.front();
            levelOrder.pop_front();
            TreeNode* temp1 = levelOrder.front();
            
            
            if(temp == NULL  ) {
                if(temp1 != NULL) {
                    levelOrder.push_back(NULL);
                    isLeftNodeAccessed = false;            
                    continue;
                }
                else
                    break;
            }else {
                cout<<"Value is "<<temp->val<<endl;
            }
            
            cout<<"Inside Loop "<<levelOrder.size()<<" is empty: "<<levelOrder.empty()<<endl;
            cout<<temp->val<<endl;
            
            if(isLeftNodeAccessed == false) {
                leftVal = temp->val;
                isLeftNodeAccessed = true;
            }
            
            if(temp->left != NULL)
                levelOrder.push_back(temp->left);
            
            if(temp->right != NULL)
                levelOrder.push_back(temp->right);
        }
        
        return leftVal;
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

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().findBottomLeftValue(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}