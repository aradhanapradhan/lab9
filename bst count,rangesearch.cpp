#include<iostream>
using namespace std;

struct node
{
  int data;
  node *par;
  node *left;
  node *right;
} *root;
int n=1;

class Bst
{
  public:
   Bst()
   {
     root=NULL;
   };
    
   int insert(int x)
   {
     node *temp=new node;
     temp->data=x;
     temp->par=temp->left=temp->right=NULL;
     node *curr=new node;
     curr=root;

     if(root==NULL)
     {
       root=temp;
     }

     else
     {
        while(1)
        {
           if(x<curr->data)
           {
             if(curr->left==NULL)
             {
               temp->par=curr;
               curr->left=temp;
               break;
             }
             else
             {
               curr=curr->left;
             }
           }

            else if(x>curr->data)
            {
              if(curr->right==NULL)
              {
                temp->par=curr;
                curr->right=temp;
                break;
              }
              else
              {
                curr=curr->right;
              }
            }
          }
          return 0;           
        }
       }
     
  int display(node *temp)
  {
    if(temp!=NULL)
    {
      display(temp->left);
      cout<<temp->data<<endl;
      display(temp->right);
      
    }
    return 0;
  }
  int countnode(node *temp)
  {
   if(temp==NULL)
   {
     return 0;
   }
   
   if(temp->left!=NULL)
   {
     n=n+1;
     n=countnode(temp->left);
   }

   if(temp->right!=NULL)
   {
     n=n+1;
     n=countnode(temp->right);
   }

   else if(temp->left==NULL || temp->right==NULL)
   {
     n=n+0;
   }
   return n;
 }
 
 void rangesearch(node *temp,int k1,int k2)
 {
   if(temp==NULL)
   {
     return ;
   }
   if(k1<temp->data)
   {
     rangesearch(temp->left,k1,k2);
   }
   if(k1>temp->data)
   {
     rangesearch(temp->right,k1,k2);
   }
   if(k1<temp->data && k2>temp->data)
   {
     cout<<temp->data<<" ";
   }
 }

 };

 int main()
 {
   Bst b;
   b.insert(10);
   b.insert(5);
   b.insert(15);
   b.display(root);
   b.countnode(root);
   cout<<"No of nodes in bst="<<n<<endl;
   b.rangesearch(root,5,15);
   return 0;
 }

     

    





     
