#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
}*root, *select, *child;

void new_node();
void initial();
void create_tree();
void check_value();
bool isLarger();
bool isLeftExist();
bool isRightExist();
void menu_2();
void inOrder(node *);
void preOrder(node *);
void postOrder(node *);
void depth();
void node_count();

void new_node()
{
    child = (node *)malloc(sizeof(node));
    cin>>child->value;
}

void initial()
{
    root = NULL;
    child = NULL;
}

void create_tree()
{
    new_node();
    if(root == NULL)
    {
        root = child;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        select = root;
        check_value();
        if(isLarger())
        {
            select->right = child;
        }
        else
        {
            select->left = child;
        }
        child->left = NULL;
        child->right = NULL;
    }
}

void check_value()
{
    if(isLarger())
    {
        if(isRightExist())
        {
            select = select->right;
            check_value();
        }
    }
    else
    {
        if(isLeftExist())
        {
            select = select->left;
            check_value();
        }
    }
}

bool isLarger()
{
    bool des;
    if(select->value < child->value)
    {
        des = true;
    }
    else
    {
        des = false;
    }
    return des;
}

bool isLeftExist()
{
    return select->left != NULL;
}

bool isRightExist()
{
    return select->right != NULL;
}

void preOrder(node *select)
{
    if (select == NULL)
	{
		return;
	}
	cout << select->value << "\n";
    preOrder(select->left);
    preOrder(select->right);
}

void inOrder(node *select)
{
	if (select == NULL)
	{
		return;
	}
    inOrder(select->left);
    cout << select->value << "\n";
    inOrder(select->right);
}

void postOrder(node *select)
{
    if (select == NULL)
	{
		return;
	}
    postOrder(select->left);
    postOrder(select->right);
    cout << select->value << "\n";
}

void menu_2()
{
    int menu;

    select = root;
    cout<<"========PRINT MENU=========="<<endl;
    cout<<"1. Preorder"<<endl;
    cout<<"2. Inorder"<<endl;
    cout<<"3. Postorder"<<endl;
    cout<<"\n";
    cout<<"Pilih: ";
    cin>>menu;

    switch(menu)
    {
        case 1:{
            preOrder(select);
            cout<<"\n";
            break;
        }
        case 2:{
            inOrder(select);
            break;
        }
        case 3:{
            postOrder(select);
            break;
        }
        default:{
            cout<<"An error occurred, back to menu"<<endl;
            system("cls");
            break;
        }
    }
}

int main()
{
    int loop;
    int menu;
    int print;

    initial();
    do
    {
        cout<<"======TREE========"<<endl;
        cout<<"1. Input tree"<<endl;
        cout<<"2. Print tree"<<endl;
        cout<<"\n";
        cout<<"Pilih: ";
        cin>>menu;

        switch(menu)
        {
            case 1:{
                create_tree();
                break;
            }
            case 2:{
                menu_2();
                break;
            }
            default:{
                cout<<"An error occurred, back to menu"<<endl;
                system("cls");
                break;
            }
        }
        cout<<"Ulangi program?"<<endl;
        cout<<"1. Yes"<<endl;
        cout<<"2. No"<<endl;
        cout<<"\n";
        cout<<"Pilih: ";
        cin>>loop;
    }
    while(loop == 1);

    return 0;
}
