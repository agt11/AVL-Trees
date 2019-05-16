#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
struct node*left;
int data;
struct node*right;
};
int i;
struct node *tree=NULL;
struct node*insert(struct node*,int);
struct node*deletee(struct node*,int);
void display(struct node*);
struct node *smallest(struct node*);
int balancefactor(struct node*);
int height(struct node*);
struct node*balancenode(struct node*);
void main()
{
int ch,val;
clrscr();
printf("\n main menu");
printf("\n 1.insert");
printf("\ 2.delete");
printf("\n 3.display");
printf("\n 4.exit");
do
{
printf("\n enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n enter the value to insert");
scanf("%d",&val);
tree=insert(tree,val);
break;
case 2:
printf("\n enter the element want to 

delete");
scanf("%d",&val);
tree=deletee(tree,val);
break;
case 3:
printf("\nroot is%d",tree->data);
display(tree);
break;
}
}while(ch!=4);
getch();
}
struct node*insert(struct node* tree,int 

val)
{
if(tree==NULL)
{
tree=(struct node*) malloc(sizeof

(struct node));
tree->data=val;
tree->left=NULL;
tree->right=NULL;
return(tree);
}
else if(val<tree->data)
tree->left=insert(tree->left,val);
else
tree->right=insert(tree->right,val);
tree=balancenode(tree);
return(tree);
}
int balancefactor(struct node*tree)
{
int l,r,b;
l=height(tree->left);
r=height(tree->right);
b=l-r;
return b;
}
int height(struct node*tree)
{
int lh,rh;
if(tree==NULL)
return 0;
else
{
lh=height(tree->left);
rh=height(tree->right);
}
if(lh>=rh)
return (lh+1);
else
return (rh+1);
}
void display(struct node*tree)
{
if(tree!=NULL)
{
printf("\n");
if(tree->left!=NULL)
printf("\nleft  child of %d is 

%d",tree->data,tree->left->data);
if(tree->right!=NULL)
printf("\nright child of %d is 

%d",tree->data,tree->right->data);
display(tree->left);
display(tree->right);
}
}
struct node*deletee(struct 

node*tree,int val)
{
struct node*aptr;
if(val<tree->data)
tree->left=deletee(tree->left,val);
else if(tree==NULL)
printf("the element you want to deletee 

is not present");
else if(val>tree->data)
tree->right=deletee(tree->right,val);
else
{
if((tree->left==NULL)&&(tree-

>right==NULL))
tree=NULL;
else if(tree->left==NULL)
{
tree=tree->right;
tree->right=NULL;
}
else if(tree->right==NULL)
{
tree=tree->left;
tree->left=NULL;
}
else
{
if(tree->right->left==NULL)
{
aptr=tree->right->right;
tree->data=tree->right->data;
tree->right=NULL;
tree->right=aptr;
}
else
{
tree->right=smallest(tree->right);
tree->data=i;
}
}
}
if(tree!=NULL)
{
tree=balancenode(tree);
}
return(tree);
}
struct node* smallest(struct node*tree)
{
struct node *aptr;
if(tree->left->left==NULL)
{
i=tree->left->data;
aptr=tree->left->right;
tree->left=NULL;
if(aptr!=NULL)
tree->left=aptr;
return tree;
}
else
{
tree->left=smallest(tree->left);
return (tree->left);
}
}
struct node*balancenode(struct 

node*tree)
{
struct node *aptr,*bptr;
int bf,ibf;
bf=balancefactor(tree);
if(bf>=2)
{
aptr=tree->left;
ibf=balancefactor(aptr);
if(ibf>=1)
{
tree->left=aptr->right;
aptr->right=tree;
tree=aptr;
}
else
{
bptr=aptr->right;
tree->left=bptr->right;
aptr->right=bptr->left;
bptr->right=tree;
bptr->left=aptr;
tree=bptr;
}
}
else if(bf<=-2)
{
aptr=tree->right;
ibf=balancefactor(aptr);
if(ibf<=-1)
{
tree->right=aptr->left;
aptr->left=tree;
tree=aptr;
}
else
{
bptr=aptr->left;
tree->right=bptr->left;
aptr->left=bptr->right;
bptr->left=tree;
bptr->right=aptr;
tree=bptr;
}
}
return (tree);
}
