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
  int showAllOperationsName();
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
           is_Element_Pr<F2>esent(root->left,data); 
           is_Element_Present(root->right,data); 
        }
      return status_is_found; 
    }

   int BinaryTree::showAllOperationsName()  {
      int operation,i;
      char arr[10][100]  = {"Insert Element","Delete  Element","Replace Element","Traverse Element","Element Present or not","Exit Program"};
      for(i=0;i<5;i++)  {
        cout<<i+1<<". ";
        cout<<arr[i]<<"\n";
      }
       cin>>operation;
       return operation;
   }


int main()  {
  BinaryTree Tree;
  int operation;
  
  while(1)   {
    operation = Tree.showAllOperationsName();
    cin>>operation;
    switch(operation)  {
        case 1:
          int elementToInsert;       
          cout<<"enter element to insert = ";
           cin>>elementToInsert;
           Tree.insert_node(elementToInsert);
        break;
 
        case 2:
        
        break;         

        case 3:

        break;

        case 4:
          cout<<"traverse Tree  =";
          Tree.traverseTree(Tree.root);
        break;

        case 5:
         int data;
         cout<<"enter data to find = ";
         cin>>data;
          if(Tree.is_Element_Present(Tree.root,data))  {
            cout<<"ElementFound\n";
         }
         else  {
            cout<<"Element Not Found\n";
         }
        break;

        case 6:
           exit(0);
         break;

        default:
        break;
    } 
    cout<<"\n";
  }
  return 0;
} 
