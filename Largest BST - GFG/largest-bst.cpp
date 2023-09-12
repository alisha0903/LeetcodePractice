//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
        class nodedata {
    public:
        int mini;       // Minimum value in the subtree rooted at this node
        int maxi;       // Maximum value in the subtree rooted at this node
        bool isbst;     // Indicates if the subtree rooted at this node is a valid BST
        int size;       // Size of the subtree rooted at this node
    };

    nodedata solve(Node* root, int& ans) {
        // Null case

    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    if (root == NULL) {
            // mini value -> INT_MAX and maxi -> INT_MIN in case of null
            // because we compare mini in case of right so right->mini > root-> data
            // and similarly, we compare maxi in case of left so left->maxi < root->data
            return { INT_MAX, INT_MIN, true, 0 };
        }

        // valid bst batana hai ki hai ya nahi so pehele left aur right ke ans pata ho
        nodedata leftans = solve(root->left, ans);
        nodedata rightans = solve(root->right, ans);

    
        nodedata currNode;
        currNode.size = leftans.size + rightans.size + 1;
        currNode.mini = min(root->data, leftans.mini);
        currNode.maxi = max(root->data, rightans.maxi);

        if (leftans.isbst && rightans.isbst && (root->data > leftans.maxi && root->data < rightans.mini)) {
            currNode.isbst = true;
            ans = max(ans, currNode.size);
        }
        else {
            currNode.isbst = false;
        }

        return currNode;
    }

    int largestBst(Node* root) {
        int ans = 0;
        nodedata temp = solve(root, ans);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends