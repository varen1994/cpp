#include<iostream>
#include<stdlib.h>
using namespace std;

struct node  {
  int data;
  struct node *right;
  struct node *left;
};

class BinaryTree  {
  public:
  struct node *root;

  BinaryTree();
  void insert_node(int data); 
  struct node *method_to_find_parent(struct node *root,int data);
  void traverseTree(struct node *root);
  bool is_Element_Present(struct node *root,int data);
  void traverse_Using_stack(vector<struct node *root>V);
};
 
  BinaryTree::BinaryTree() {
   root = NULL; 
  } 

  void BinaryTree::insert_node(int data)  {
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); 
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    if(root==NULL)
    {
      root = newNode;
    } 
    else   {
      struct node *findParent = method_to_find_parent(root,data);
       if(findParent->data>data)  {
           findParent->left = newNode;
        }
       else  {
           findParent->right = newNode;
        } 
    }

  } 

  struct node * BinaryTree::method_to_find_parent(struct node *root,int data)  {
     static struct node *previousParent;  
     
     if(root==NULL)  {
       return previousParent;
     } 
     
     previousParent = root;
 
     if(root->data>data)  {
        method_to_find_parent(root->left,data);
      }
      else  {
        method_to_find_parent(root->right,data); 
      } 
     
   } 
    

   void BinaryTree::traverseTree(struct node *root)  {
        if(root!=NULL)  { 
           traverseTree(root->left);
           cout<<root->data<<" ";
           traverseTree(root->right); 
         }   
       return ; 
    }

    bool BinaryTree::is_Element_Present(struct node *root,int data)  { 
       static bool status_is_found = false; 
       if(root!=NULL)  {
           if(root->data==data)  {
              status_is_found = true;
           }
           is_Element_Present(root->left,data); 
           is_Element_Present(root->right,data); 
        }
      return status_is_found; 
    }

    void BinaryTree::traverse_Using_stack(vector<struct node root>V)   {
      struct node *temp = V(V.size()-1);
      cout<temp->data;
      V.pop_back(V.size()-1);
      if(temp!=NULL)  {  
        if(temp->right!=NULL)  {
            V.push_back(temp->right);
        }
        if(temp->left!=NULL)  {
            V.push_back(temp->left);
        }
      }
      traverse_Using_stack(V);
       return ;
    }



int main()  {
  BinaryTree Tree;
  Tree.insert_node(100);
  Tree.insert_node(50);
  Tree.insert_node(25);
  Tree.insert_node(15);
  Tree.insert_node(40); 
  Tree.insert_node(120);
  Tree.insert_node(101);
  Tree.traverseTree(Tree.root);
  cout<<"status is \n"<<Tree.is_Element_Present(Tree.root,1111)<<"\n";
  vector<struct node root>V;
  V.push_back(Tree.root);
  BinaryTree.traverse_Using_stack(V);
  return 0;
} 
