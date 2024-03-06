#include <iostream>
#include <string>

using namespace std;

struct TreeNode{
    double data;        // Значение соединительного элемента узла дерева 
    TreeNode* left;     // Указатель на левую ветку дерева
    TreeNode* right;    // Указатель на правую ветку дерева
};

// Создание узла дерева с нулевыми указателями веток
TreeNode* createTreeNode(double data){
    TreeNode* newNode = new TreeNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


void addData(TreeNode* root, TreeNode* newNode){
    if (newNode->data < root->data)
    {
        if (root->left == nullptr) root->left = newNode;
        else addData(root->left, newNode);
    }
    else
    {
        if (root->right == nullptr) root->right = newNode;
        else addData(root->right, newNode);
    }
}

TreeNode* createBalancedTree(int arr[], int start, int end){
    if (start > end) return nullptr;

    int middle = (start + end) / 2;
    TreeNode* first = createTreeNode(arr[middle]);
    first->left = createBalancedTree(arr, start, middle - 1);
    first->right = createBalancedTree(arr, middle + 1, end);

    return first;
}

void printTree(TreeNode* first, int space){
    if (first == nullptr) return;

    space += 10;

    printTree(first->left, space);
    cout << endl;
    // for (int i = 10; i < space; i++) cout << " ";
    cout << string(space, '.');
    cout << first->data << "\n"; 
    printTree(first->right, space); 
}

//вывод дерева поиска 
void printSearchTree(TreeNode* root, int space) { 
 
    if (root == nullptr) { 
        return; 
    } 
 
    space += 2; 
 
    printSearchTree(root->left, space); 
 
    cout << endl; 
    for (int i = 0; i < space; ++i) { 
        cout << " "; 
    } 
    cout << root->data << "\n"; 
  
 
    printSearchTree(root->right, space); 
} 

int main(){
    setlocale(LC_ALL, "rus");

    int arr[] = { 1, 8, 3, 4, 5, 6, 7, 2}; 
    int arrSize = sizeof(arr) / sizeof(arr[0]); 

    TreeNode* first = createBalancedTree(arr, 0, arrSize - 1);
    TreeNode* root = createTreeNode(0);

    for (int i = 0; i < 8; i++) { 
        TreeNode* el = createTreeNode(arr[i]); 
        addData(root, el); 
    } 
 
    cout << "Идеально сбалансированное дерево:\n"; 
    printTree(first, 0); 

    return 0;
}