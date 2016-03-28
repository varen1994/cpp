#include<iostream>
#include<stdlib.h>
using namespace std;

struct node 
{
  int data;
  struct node *next;
};

class LinkedList
{
  public:
  struct node *root; 
  struct node *insert_at_beginning(struct node*,int);
  struct node *insert_at_last(struct node*,int );
  struct node *insert_at_index(struct node* ,int ,int );
  struct node * delete_at_index(struct node*,int );
  struct node * delete_node_where_data(struct node*,int );
  struct node* concatenate_ll(struct node*,struct node*);
  void change_value_where_data(struct node*,int ,int );
  struct node* delete_ll(struct node*  );
  struct node *reverse_ll(struct node *);
  void traverse_ll(struct node *); 
};


void LinkedList::traverse_ll(struct node *root)
{
 cout<<"\n";
  while(root!=NULL)
  {
    cout<<root->data<<" ";
    root = root->next;
  }
return ;
}

struct node* LinkedList::insert_at_beginning(struct node* root,int new_data)
{
  struct node *new_node= (struct node *)malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = root;
  return new_node;
}

struct node* LinkedList::insert_at_last(struct node* root,int new_data)
{
  struct node* temp = root;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->next = NULL;
  new_node->data = new_data;
  while(temp->next!=NULL)
  {
     temp= temp->next;
  }
  temp->next = new_node;
return root; 
}

void LinkedList::change_value_where_data(struct node* root,int old_value,int new_value)
{
  while(root!=NULL)
  {
    if(root->data==old_value)
    {
      root->data = new_value;
    }
    root = root->next;
  }
}


struct node* LinkedList::insert_at_index(struct node *root,int index,int new_data)
{
  struct node *temporary = root;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = new_data;
  if(index==0)
  {
    new_node->next = root;
    return new_node;
  }
  else
  {
    while(index--)
    {
      root = root->next;
    } 
    struct node *temp = root->next;
    root->next = new_node;
    new_node->next = temp;
  }
 return temporary;
}


struct node* LinkedList::concatenate_ll(struct node *root,struct node *root2)
{
  struct node *temp = root;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = root2;
return root;
}

struct node* LinkedList::delete_ll(struct node* root)
{
  struct node *next_node = root->next;
  if(root==NULL)
  {
    cout<<"EMPTY LIST ALREADY";
    return NULL;
  }
  while(root!=NULL)
  {
    free(root);
    root = next_node;
    next_node = next_node->next;
  }
return NULL;
}


struct node *LinkedList::reverse_ll(struct node *root)
{
  struct node *temp = NULL;
  struct node *temp2;
  while(root!=NULL)
  {
    temp = insert_at_beginning(temp,root->data);
    temp2 = root->next;
    free(root);
    root = temp2;
  }
 return temp;
}

struct node* LinkedList::delete_node_where_data(struct node *root,int data)
{
  struct node *temp = NULL;
  struct node *temp2;
  while(root!=NULL)
  {
     if(data!=root->data)
     {
      temp = insert_at_last(temp,root->data);
      this->traverse_ll(temp);
     }
     temp2 = root->next;
     free(root);
     root = temp2;
  }
return temp;
}

struct node* LinkedList::delete_at_index(struct node *root,int index)
{
  struct node *temp2 = root;
  struct node *temp = root->next;
  if(index==0)
  {
    free(root);
    return temp;
  }
  else
  {
    index--;
    while(index--)
    {
       temp = temp->next;
       root = root->next;
    }
    root->next = temp->next;
    free(temp);
  }
return temp2;
}


int main()
{
  LinkedList ll;
  ll.root = NULL;
  ll.root = ll.insert_at_beginning(ll.root,10);
  ll.root = ll.insert_at_beginning(ll.root,20);
  ll.root = ll.insert_at_beginning(ll.root,20); 
  ll.root = ll.insert_at_last(ll.root,0);
  ll.traverse_ll(ll.root);
  ll.root = ll.reverse_ll(ll.root);
  cout<<"\n AFTER REVERSING \n";
  ll.root = ll.insert_at_last(ll.root,100);
  ll.root = ll.insert_at_index(ll.root,1,1110);
  ll.traverse_ll(ll.root);;
  ll.change_value_where_data(ll.root,20,123);
  ll.root = ll.delete_at_index(ll.root,100);
   cout<<" deleting at index 0 ";
   ll.traverse_ll(ll.root);
  return 0;
}

