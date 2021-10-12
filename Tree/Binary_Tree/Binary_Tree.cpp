#include <bits/stdc++.h>
using namespace std;

map <int , int> HashMap;                                //declaration of Hash-map used in the program
map <int , int> :: iterator it;                         //iterator for the Hash-map

map <int , pair <int , int> > HashMap2;                  //declaration of Hash-map (having key and integer pair) used in the program
map <int , pair <int , int> > :: iterator it2;           //iterator for the Hash-map

map <int , vector <int> > m;
map <int , vector <int> > :: iterator it3;

struct treenode                                          //structure of the binary tree
{
    int info;                                            //data part
    struct treenode *left,*right;                        //left and right node which will contain address of left and right subtree
};

//1-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode* create()                                //create function for binary tree creation
{
    int data;
    struct treenode *tree;                               //variable of the structure
    tree = new treenode;                                 //dynamically allocating memory for tree-node

    cout<<"\nEnter data to be inserted or type -1 for no insertion : ";
    cin>>data;                                           //input from the user

    if(data==-1)                                         //condition for termination
        return 0;

    tree->info=data;                                     // assigning value from user into tree.
                                                         // recursively calling create function for left and right sub tree
    cout<<"\nEnter left child of "<<data;
    tree->left=create();

    cout<<"\nEnter right child of "<<data;
    tree->right=create();

    return tree;                                        //returning the created tree
};

//-----------------------------------------------------------------------------------------------------------------------------------------------
//Node by node creation

struct treenode* createnew()                            //following the same logic, creating only one node
{
    int data;
    struct treenode *tree;
    tree=(struct treenode*) malloc(sizeof(struct treenode));
    printf("\nEnter data to be inserted or type -1 for no insertion : ");
    scanf("%d",&data);

    if(data==-1)
        return NULL;

    tree->info=data;
                                                        //as only one node is created during each call so left=right=NULL
    tree->left = NULL;
    tree->right = NULL;

    return tree;                                        //returning the created node
};

//2-----------------------------------------------------------------------------------------------------------------------------------------------

void preorder(struct treenode *root)                    //pre-order traversal without using recursion
{
    if(root == NULL)
        return;

    stack <treenode*> s;                                //using tree-node type stack STL
    while((root != NULL) || (!s.empty()))               //will execute the loop until the stack is not empty or root is not NULL
    {
        if(root != NULL)
        {
            cout << root->info << " ";                  //printing the root as in pre-order first comes root then left subtree then right subtree

            s.push(root);                               //push the node into the stack if node is not NULL

            root = root->left;                          //going to left subtree
        }
        else
        {
            root = s.top();                             //removing the top of stack and making it root to go he its right
            s.pop();
            root = root -> right;
        }
    }
    cout<<endl;

}

//3-----------------------------------------------------------------------------------------------------------------------------------------------

void inorder(struct treenode *root)                     //in-order traversal without using recursion
{
    if(root == NULL)
        return;

    stack <treenode*> s2;                               //using tree-node type stack STL
    while((root != NULL) || (!s2.empty()))
    {
        if(root != NULL)
        {
            s2.push(root);                              //pushing the root and going to its left, as in in-order left then root then right
            root = root->left;
        }
        else
        {
            root = s2.top();                             //removing the top of stack and making it root to go he its right
            s2.pop();
            cout << root->info << " ";                   //printing the root's data then going to right
            root = root->right;
        }
    }
    cout<<endl;

}

//4-----------------------------------------------------------------------------------------------------------------------------------------------

void postorder(struct treenode *root)                   //post-order traversal without using recursion
{
    if(root == NULL)
        return;

    stack <treenode*> s3;
    struct treenode *previous = NULL;                   //will need an extra pointer so declaring it

    do
    {
        while(root != NULL)
        {
            s3.push(root);
            root = root->left;
        }

        while(root == NULL && (!s3.empty()))
        {
            root = s3.top();
            if(root->right == NULL || root->right == previous)
            {
                cout<<root->info<<" ";
                s3.pop();
                previous = root;
                root = NULL;

            }
            else
                root = root->right;
        }

    }
    while(!s3.empty());

    cout<<endl;

}

//5-----------------------------------------------------------------------------------------------------------------------------------------------

void levelorder(struct treenode *root)                        //level-order traversal without using recursion
{
    if(root == NULL)
        return;

    queue <treenode*> q;                                      //using queue for traversal

    cout<<root->info<<" ";
    q.push(root);

    while(!q.empty())
    {
        root = q.front();
        q.pop();

        if(root->left)
        {
            cout<<root->left->info<<" ";
            q.push(root->left);
        }
        if(root->right)
        {
            cout<<root->right->info<<" ";
            q.push(root->right);
        }
    }

    cout<<endl;
}

//6-----------------------------------------------------------------------------------------------------------------------------------------------

int FindMax(struct treenode *root)              //Finding maximum using iterative method
{
    if(root == NULL)
        return 0;

    queue <treenode*> q;
    int max;
    struct treenode *temp;

    max=root->info;
    q.push(root);

    while(!q.empty())
    {
        root = q.front();
        temp=root;
        q.pop();

        if(max < temp->info)
            max = temp->info;

        if(root->left)
        {
            q.push(root->left);
        }
        if(root->right)
        {
            q.push(root->right);
        }
    }
    return max;
}

//7-----------------------------------------------------------------------------------------------------------------------------------------------

int FindElement(struct treenode *root, int data)
{
    if(root == NULL)
        return 0;

    queue <treenode*> q;
    struct treenode *temp;
    if(!root)
        return 0;

    else
    {
        q.push(root);

        while(!q.empty())
        {
            root = q.front();
            temp=root;
            q.pop();

            if(data == temp->info)
                return 1;

            if(root->left)
            {
                q.push(root->left);
            }
            if(root->right)
            {
                q.push(root->right);
            }
        }
        return 0;
    }
}

//8-----------------------------------------------------------------------------------------------------------------------------------------------

void insertelement(struct treenode *root)
{
    if(root == NULL)
        return;

    struct treenode *newnode, *temp;
    newnode = createnew();

    queue <treenode *> q;

    q.push(root);
    while( !q.empty() )
    {
        root = q.front();
        temp = root;
        q.pop();

        if(temp->left)
            q.push(temp->left);
        else
        {
            temp->left = newnode;
            break;
        }
        if(temp->right)
            q.push(temp->right);
        else
        {
            temp->right = newnode;
            break;
        }
    }
}

//9-----------------------------------------------------------------------------------------------------------------------------------------------

int sizeoftree(struct treenode *root)
{
    if(root == NULL)
        return 0;

    queue <treenode *> q;
    struct treenode *temp;
    int count = 0;

    q.push(root);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        count++ ;

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return count;
}

//10-----------------------------------------------------------------------------------------------------------------------------------------------

int findsum(struct treenode *root)
{
    if(root == NULL)
        return 0;

    return (root->info + findsum(root->left) + findsum(root->right));
}

//11-----------------------------------------------------------------------------------------------------------------------------------------------

void reversetree(struct treenode *root)
{
    if(root == NULL)
        return;

    queue <treenode *> q;
    stack <int> s;

    struct treenode *temp;

    q.push(root);

    while( !q.empty() )
    {
        temp = q.front();
        q.pop();

        s.push(temp->info);                                             //pushing every countered node's data into stack

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }

    while( !s.empty() )
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

//12-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode* FindElementnode(struct treenode *root, int data)
{
    if(root == NULL)
        return NULL;

    queue <treenode*> q;

    struct treenode *temp;
    if(!root)
        return 0;

    else
    {
        q.push(root);

        while(!q.empty())
        {
            root = q.front();
            temp=root;
            q.pop();

            if(data == temp->info)
                return temp;

            if(root->left)
            {
                q.push(root->left);
            }
            if(root->right)
            {
                q.push(root->right);
            }
        }
        return NULL;
    }
}

struct treenode* deepestnode (struct treenode *root)
{
    queue <treenode *> q;

    q.push(root);

    while( !q.empty() )
    {
        root = q.front();

        q.pop();

        if(root -> left)
            q.push(root -> left);
        if(root -> right)
            q.push(root -> right);
    }

    return (root);
}

void neworder(struct treenode *view, struct treenode *temp, struct treenode *deep)
{
    queue <treenode*> q;

    if(view->info == temp->info)
    {
        view = deep;
        cout<<view->info<<" ";
        q.push(view);
    }
    else
    {
        cout<<view->info<<" ";
        q.push(view);
    }

    while(!q.empty())
    {
        view = q.front();
        q.pop();

        if(view -> left)
        {
            if(view->left->info == temp->info)
                cout<<deep->info<<" ";
            else
                cout<<view->left->info<<" ";

            if(view->left->info == temp->info)
            {
                deep->left = view->left->left;
                deep->right = view->left->right;

                view->left = deep;

                q.push(view->left);
            }
        }
        if(view->right)
        {
            if(view->right->info == temp->info)
                cout<<deep->info<<" ";
            else
                cout<<view->right->info<<" ";

            if(view->right->info == temp->info)
            {
                deep->left = view->right->left;
                deep->right = view->right->right;

                view->right = deep;
                q.push(view->right);
            }
        }
    }
    delete view;
    cout<<endl;
}

void deletenode(struct treenode *root, int data)
{
    struct treenode *view;
    view = new treenode;
    view = root;
    struct treenode *temp,*deep;
    temp = FindElementnode(root, data);
    deep = deepestnode(root);
    cout<<"\nNew tree (level order) : \n";

    neworder(view, temp, deep);

}

//13-----------------------------------------------------------------------------------------------------------------------------------------------

void deletetree(struct treenode *root)
{
    delete root;
}

//14-----------------------------------------------------------------------------------------------------------------------------------------------

int findlevel(struct treenode *root , int data , int level)
{
    if(root == NULL)
        return 0;

    int a;

    if(root->info == data)
        return level;

    a = findlevel(root->left , data , level+1);

    if(a != 0)
        return a;

    a = findlevel (root->right , data , level+1);

    return a;
}

//15-----------------------------------------------------------------------------------------------------------------------------------------------

int height(struct treenode *root)
{
    int x,y;
    if(root != NULL)
    {
        x=height(root->left);
        y=height(root->right);

        if(x>y)
            return x+1;                                                // leaf node has one height so x or y + 1
        else
            return y+1;
    }
    return 0;
}

//16,41,42-------------------------------------------------------------------------------------------------------------------------------------------

int deepest(struct treenode *root)
{
    if(root == NULL)
        return 0;

    queue <treenode *> q;
    q.push(root);

    while( !q.empty() )
    {
        root = q.front();

        q.pop();

        if(root -> left)
            q.push(root -> left);
        if(root -> right)
            q.push(root -> right);
    }
    return (root -> info);
}

//17-----------------------------------------------------------------------------------------------------------------------------------------------

int leafnodes(struct treenode *root)                    //iterative approach
{
    struct treenode *temp;
    queue <treenode *> q;
    int count = 0;

    if( !root )
        return 0;

    q.push(root);

    while( !q.empty() )
    {
        temp = q.front();
        q.pop();

        if(!temp->left && !temp->right)
            count++;
        else
        {
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

    }
    return count;
}

//18-----------------------------------------------------------------------------------------------------------------------------------------------

int diameter(struct treenode *root)
{
    if(root == NULL)
        return  0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    int rootdiamter = (lheight + rheight + 1);
    int largerdiameter = max(ldiameter,rdiameter);
    int answer = max (rootdiamter, largerdiameter);
    return answer;
}

//19-----------------------------------------------------------------------------------------------------------------------------------------------

void maxlevelsum(struct treenode *root)
{
    queue <treenode *> q1,q2;
    struct treenode *temp;

    int level = 0, sum = 0, maxsum = 0, answer = 0;

    if(root == NULL)
        cout<<"\nLevel an sum = 0"<<endl;

    q1.push(root);
    answer = 1;

    while( !q1.empty() || !q2.empty() )
    {
        if(!q1.empty())
        {
            level++;
            sum = 0;
            while(!q1.empty())
            {
                temp = q1.front();
                q1.pop();

                if(temp -> left)
                    q2.push(temp -> left);
                if(temp -> right)
                    q2.push(temp -> right);

                sum = sum + (temp->info);
            }
        }

        if(sum > maxsum)
        {
            maxsum = sum;
            answer = level;
        }

        if(!q2.empty())
        {
            level++;
            sum = 0;
            while(!q2.empty())
            {
                temp = q2.front();
                q2.pop();

                if(temp -> left)
                    q1.push(temp -> left);
                if(temp -> right)
                    q1.push(temp -> right);

                sum = sum + (temp->info);
            }
        }
        if(sum > maxsum)
        {
            maxsum = sum;
            answer = level;
        }
    }
    cout<<"\nMaximum level is = "<<answer<<endl;
    cout<<"Sum at the maximum level is = "<<maxsum<<endl;
}

//20-----------------------------------------------------------------------------------------------------------------------------------------------

void root_to_leaf_path(struct treenode *root , vector <int> v)
{
    if(root == NULL)
        return;

    v.push_back(root->info);

    if(root->left == NULL && root->right == NULL)
    {
        for(int i=0 ; i < v.size() ; i++)
            cout<<v[i]<<"  ";
        cout<<endl;
    }
    root_to_leaf_path(root->left,v);
    root_to_leaf_path(root->right,v);

    v.pop_back();
}

void root_to_leaf(struct treenode *root)
{
    vector <int> v;
    root_to_leaf_path(root , v);
}

/*
    OTHER METHOD : USING ARRAY
void root_to_leaf_path(struct treenode* root , int arr[] , int index)
{
    if(root == NULL)
        return;

    arr[index] = root->info;
    index++;

    if(root->left == NULL && root->right == NULL)
    {
        for(int i=0 ; i < index ; i++)
            cout<<arr[i]<<"  ";
        cout<<endl;
    }

    root_to_leaf_path(root->left , arr , index);
    root_to_leaf_path(root->right , arr , index);
}

void root_to_leaf(struct treenode *root)
{
    int arr[100];
    int index = 0;
    root_to_leaf_path(root , arr , index);
}
*/

//21-----------------------------------------------------------------------------------------------------------------------------------------------

void checkpathsum(struct treenode* root , int arr[] , int index , int sum)
{
    if(root == NULL)
        return;

    arr[index] = root->info;
    index++;

    if(root->left == NULL && root->right == NULL)
    {
        int temp=0;
        for(int i=0 ; i < index ; i++)
            temp = temp + arr[i];
        if(temp == sum)
        {
            cout<<"\nSUM PATH IS PRESENT . The path is : ";
            for(int i = 0 ; i < index  ; i++)
                cout<<arr[i]<<"  ";
            cout<<endl;
        }
        else
        {
            cout<<"\nThis path is not the sum path : ";
            for(int i = 0 ; i < index  ; i++)
                cout<<arr[i]<<"  ";
            cout<<endl;
        }
    }

    checkpathsum(root->left , arr , index , sum);
    checkpathsum(root->right , arr , index , sum);
}

void checksum(struct treenode *root , int sum)
{
    int arr[100];
    int index = 0;
    checkpathsum(root , arr , index , sum);
}
// CAN BE MADE USING VECTOR AND STACK AS WELL SIMILARLY.

//22-----------------------------------------------------------------------------------------------------------------------------------------------

int maxlevelleft=0;
void leftview(struct treenode *root , int level)
{
    if(root == NULL)
        return;

    if(level >= maxlevelleft)
    {
        cout<<root->info<<" ";
        maxlevelleft++;
    }

    leftview(root->left , level+1);
    leftview(root->right , level+1);
}

//23-----------------------------------------------------------------------------------------------------------------------------------------------

int maxlevelright=0;
void rightview(struct treenode *root , int level)
{
    if(root == NULL)
        return;

    if(level >= maxlevelright)
    {
        cout<<root->info<<" ";
        maxlevelright++;
    }

    rightview(root->right , level+1);
    rightview(root->left , level+1);
}

//24-----------------------------------------------------------------------------------------------------------------------------------------------

void topview(struct treenode *root , int level)
{
    if(root == NULL)
        return;

    int i = HashMap.count(level);
    if (i == 0)
        HashMap[level] = root->info;

    topview(root->left , level-1);

    topview(root->right , level+1);

    HashMap[level] = root->info;
    return;

}

//25-----------------------------------------------------------------------------------------------------------------------------------------------

void bottomview(struct treenode *root , int level , int height)
{
    if(root == NULL)
        return;

    if(height >= HashMap2[level].second)
    {
        HashMap2[level] = {root->info , height};
    }

    bottomview(root->left , level-1 , height+1);
    bottomview(root->right , level+1 , height+1);

    return;
}

//26-----------------------------------------------------------------------------------------------------------------------------------------------

void printleafnodes(struct treenode *root)
{
    if(root == NULL)
        return;

    if(root->left==NULL && root->right==NULL)
        cout<<root->info<<"  ";
    printleafnodes(root->left);
    printleafnodes(root->right);
}

void printleftboundary(struct treenode *root)
{
    if(root == NULL)
        return;

    if(root->left)
    {
        cout<<root->info<<"  ";
        printleftboundary(root->left);
    }
    else if(root->right)
    {
        cout<<root->info<<"  ";
        printleftboundary(root->right);
    }
}

void printrightboundary(struct treenode *root)
{
    if(root == NULL)
        return;

    if(root->right)
    {
        printrightboundary(root->right);
        cout<<root->info<<"  ";
    }
    else if(root->left)
    {
        printrightboundary(root->left);
        cout<<root->info<<"  ";
    }
}

void printboundarynodes(struct treenode *root)
{
    if(root == NULL)
        return;
    else
        cout<<root->info<<"  ";

    printleftboundary(root->left);

    printleafnodes(root->left);
    printleafnodes(root->right);

    printrightboundary(root->right);
}

//27-----------------------------------------------------------------------------------------------------------------------------------------------

void mirrortree(struct treenode *root)
{
    if(root != NULL)
    {
        mirrortree(root->left);
        mirrortree(root->right);

        struct treenode *temp;

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return;
}

//28-----------------------------------------------------------------------------------------------------------------------------------------------

int findPath(struct treenode *root, vector <int> &path , int k)
{
    if(root == NULL)
        return 0;

    path.push_back(root->info);

    if(root->info == k)
        return 1;

    if(findPath(root->left , path , k))
        return 1;
    if(findPath(root->right , path , k))
       return 1;

    path.pop_back();

    return 0;
}

int findlca(struct treenode *root, int n1, int n2)
{
    int i;
    vector <int> path1, path2;

    findPath(root, path1, n1);
    findPath(root, path2, n2);

    for (i = 0 ; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;

    return (path1[i-1]);
}

/*
OTHER WAY - RECRSIVELY
struct treenode* findlca(struct treenode *root , int n1 , int n2)
{
    struct  treenode *left,*right;

    if(root == NULL)                                //base condition
        return root;

    if(root->info == n1 || root->info == n2)        //found either n1 or n2
        return root;

    left = findlca(root->left , n1 , n2);           //calling left subtree recursively
    right = findlca(root->right , n1 , n2);         //calling right subtree recursively

    if(left == NULL && right == NULL)               //if both left and right return NULL which means not found n1 and n2
        return NULL;

    if(left != NULL && right != NULL)               //our LCA as both n1 and n2 are found
        return root;

    else
    {
        return (left != NULL ? left : right);       //return the non-null node which is either n1/n2
    }

};

*/

//29-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode* createnewnode(int data)
{
    struct treenode *tree;
    tree=(struct treenode*) malloc (sizeof(struct treenode));

    if(data == -1)
        return NULL;

    tree->info = data;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

int preindex = 0;

int getindex(int data , vector <int> in , int start , int endindex)
{
    for(int i = 0 ; i < in.size() ; i++)
    {
        if(in[i] == data)
            return i;
    }

    return -1;
}

struct treenode* createtree(vector <int> pre , vector <int> in , int start , int endindex)
{
    struct treenode *root;

    if(start > endindex)
        return NULL;

    root = createnewnode(pre[preindex++]);

    if(start == endindex)
        return root;

    int inorderindex = getindex(root->info , in , start , endindex);

    root->left = createtree(pre , in , start , inorderindex-1 );
    root->right = createtree(pre , in , inorderindex+1 , endindex);

    return root;
}

//30-----------------------------------------------------------------------------------------------------------------------------------------------

void allancestorpath(struct treenode* root , int data , vector <int> path)
{
    if(root == NULL)
        return;

    path.push_back(root->info);

    if(root->info == data)
    {
        cout<<"\nPath : ";
        for(int i = 0 ; i < path.size() ; i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    allancestorpath(root->left , data , path);
    allancestorpath(root->right , data , path);
}

void allancestors(struct treenode* root , int data )
{
    vector <int> path;

    allancestorpath(root , data , path);
}

//31-----------------------------------------------------------------------------------------------------------------------------------------------

void zigzag(struct treenode* root)
{
    stack <treenode *> s1,s2;
    struct treenode *temp;

    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {
        while( !s1.empty() )
        {
            temp = s1.top();
            cout<< temp -> info <<" ";
            s1.pop();

            if(temp -> left)
                s2.push(temp -> left);

            if(temp -> right)
                s2.push(temp -> right);
        }

        while( !s2.empty() )
        {
            temp = s2.top();
            cout<< temp -> info <<" ";
            s2.pop();

            if(temp -> right)
                s1.push(temp -> right);

            if(temp -> left)
                s1.push(temp -> left);
        }
    }
}

//32-----------------------------------------------------------------------------------------------------------------------------------------------

void verticalorder(struct treenode *root , int level , map<int , vector <int> > &m)
{
    if(root ==  NULL)
        return;

    m[level].push_back(root->info);

    verticalorder(root->left , level-1 , m);
    verticalorder(root->right , level+1 , m);
}

//33-----------------------------------------------------------------------------------------------------------------------------------------------

void verticalsum(struct treenode *root , int level)
{
    if( root == NULL )
        return;

    verticalsum(root -> left , level-1 );

    HashMap[level] = HashMap[level] + (root->info);

    verticalsum(root -> right, level+1 );

    return;
}

//34-----------------------------------------------------------------------------------------------------------------------------------------------

void levelsum(struct treenode *root , int level , map<int ,int> &m)
{
    if(root == NULL)
        return;

    m[level] = m[level]+(root->info);

    levelsum(root->left , level+1 , m);
    levelsum(root->right , level+1 , m);
}

//35-----------------------------------------------------------------------------------------------------------------------------------------------

void maximumwidth(struct treenode *root , int level)
{
    if(root == NULL)
        return;

    HashMap[level] = HashMap[level] + 1;

    maximumwidth(root->left , level+1);
    maximumwidth(root->right , level+1);
}

//36-----------------------------------------------------------------------------------------------------------------------------------------------

bool ifmirrorstructure(struct treenode *n1 , struct treenode *n2)
{
    if(n1==NULL && n2==NULL)
        return true;

    if(n1==NULL || n2==NULL)
        return false;

    return (ifmirrorstructure(n1->left , n2->right) && ifmirrorstructure(n1->right , n2->left));

}

bool foldable(struct treenode *root)
{
    if(root == NULL)
        return false;

    return ifmirrorstructure(root->left , root->right);
}

//37-----------------------------------------------------------------------------------------------------------------------------------------------

void doubletree(struct treenode* root)
{
    if(root == NULL)
        return;

    doubletree(root->left);
    doubletree(root->right);

    treenode *newnode = createnewnode(root->info);
    newnode->left = root->left;
    root->left = newnode;
}

//38-----------------------------------------------------------------------------------------------------------------------------------------------

int ifBalanced(struct treenode *root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    int lh = ifBalanced(root->left);
    if(lh == -1)
        return -1;

    int rh = ifBalanced(root->right);
    if(rh == -1)
        return -1;

    if(abs(lh-rh) > 1)
        return -1;

    return (abs(lh-rh) + 1);

}

//39-----------------------------------------------------------------------------------------------------------------------------------------------

void minheight(struct treenode *root , map <int,int> &HashMap , int level)
{
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
        HashMap[level] = root->info;

    minheight(root->left,HashMap,level+1);
    minheight(root->right,HashMap,level+1);

    return;
}

//40-----------------------------------------------------------------------------------------------------------------------------------------------

int toplevel = 0;
int check_leaf_level(struct treenode *root , int level)
{
    if(root == NULL)
        return 1;

    if(root->left == NULL && root->right == NULL)
    {
        if(toplevel == 0)
        {
            toplevel = level;
            return 1;
        }
        else if(level == toplevel)
            return 1;
        else
            return 0;
    }
    return(check_leaf_level(root->left , level+1) && check_leaf_level(root->right , level+1));
}


// 41 and 42 are above named deepest();

//43-----------------------------------------------------------------------------------------------------------------------------------------------

int deepestodd=0;
void deepestoddleaf(struct treenode *root , int level)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
    {
        if(level%2 != 0)
        {
            if(level > deepestodd)
                deepestodd = level;
        }
    }

    deepestoddleaf(root->left , level+1);
    deepestoddleaf(root->right , level+1);
}

//44-----------------------------------------------------------------------------------------------------------------------------------------------

struct treenode* remove_lesser_node(struct treenode *root , int level , int k)
{
    if(root == NULL)
       return NULL;
    root->left = remove_lesser_node(root->left , level+1 , k);
    root->right = remove_lesser_node(root->right , level+1 , k);

    if(root->left == NULL && root->right == NULL)
    {
        if(level < k)
           return NULL;
    }
    return root;
}

//45-----------------------------------------------------------------------------------------------------------------------------------------------

int findpattern(struct treenode *root , int a[] , int index , int size)
{
    if(root == NULL)
        return 0;

    if(root->info != a[index])
        return 0;

    if(root->left == NULL && root->right == NULL)
    {
        if(size-1 == index)
            return 1;
    }

    return (findpattern(root->left , a , index+1 , size) || findpattern(root->right , a , index+1 , size));
}

//46-----------------------------------------------------------------------------------------------------------------------------------------------

void findparent(struct treenode *root , int data)
{
    if(root==NULL || root->info==data)
        return;

    else if(root->left != NULL && root->left->info==data)
    {
        cout<<"\nParent = "<<root->info<<endl;
        return;
    }
    else if(root->right != NULL && root->right->info==data)
    {
        cout<<"\nParent = "<<root->info<<endl;
        return;
    }

    findparent(root->left , data);
    findparent(root->right , data);
}

//47-----------------------------------------------------------------------------------------------------------------------------------------------

int findsibling(struct treenode *root , int data)
{
    if(root == NULL  || root->info == data || root->left == NULL || root->right == NULL)
        return 0;

    if(root->right !=NULL && root->left->info == data)
        return root->right->info;

    if(root->left !=NULL && root->right->info == data)
        return root->left->info;

    findsibling(root->left , data);
    findsibling(root->right , data);
}

//48-----------------------------------------------------------------------------------------------------------------------------------------------

int checksibling(struct treenode *root , int data1 , int data2)
{
    if(root == NULL)
        return 0;

    if(root->left->info == data1 && root->right->info == data2)
        return 1;

    if(root->left->info == data2 && root->right->info == data1)
        return 1;

    return (checksibling(root->left , data1 , data2) || checksibling(root->right , data1 , data2));
}

//49-----------------------------------------------------------------------------------------------------------------------------------------------

int distance(struct treenode *root , int data , int len)
{
    if(root == NULL)
        return 0;

    if(root->info == data)
        return len;

    int left = distance(root->left , data , len+1 );

    if(left == 0)
        return (distance(root->right , data , len+1 ));
}

//50 is inside case 50;

//51-----------------------------------------------------------------------------------------------------------------------------------------------

void serialize(struct treenode *root , vector <int> &pre)
{
    if(root == NULL)
    {
        pre.push_back(-1);
        return;
    }

    pre.push_back(root->info);

    serialize(root->left , pre);
    serialize(root->right , pre);
}

//52-----------------------------------------------------------------------------------------------------------------------------------------------

int deserializeindex=0;
struct treenode* deserialize(int pre[])
{
    if(pre[deserializeindex] == -1)
    {
        deserializeindex++;
        return NULL;
    }
    treenode *newnode = createnewnode(pre[deserializeindex++]);

    newnode->left = deserialize(pre);
    newnode->right = deserialize(pre);

    return newnode;
}

//53-----------------------------------------------------------------------------------------------------------------------------------------------

int currenval=0;
int isBST(struct treenode *root)
{
    if(root == NULL)
        return 1;

    if(!isBST(root->left))
        return 0;

    if(currenval != 0 && currenval > root->info)
            return 0;

    currenval=root->info;

    return(isBST(root->right));
}

//54-----------------------------------------------------------------------------------------------------------------------------------------------

treenode *head = NULL;
treenode *previous = NULL;
void convert(struct treenode *root)
{
    if(root == NULL)
        return;

    convert(root->left);

    if(previous == NULL)
    {
        head = root;
        previous = root;
    }
    else
    {
        previous->right = root;
        //root->left = previous;
        previous = root;
    }

    convert(root->right);
}

//55-----------------------------------------------------------------------------------------------------------------------------------------------

int checkchildsum(struct treenode *root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 1;
    else
    {
        int sum=0;

        if(root->left)
            sum = sum + root->left->info;

        if(root->right)
            sum = sum + root->right->info;

        if(sum == root->info)
            return 1;
        else
            return 0;

        return(checkchildsum(root->left) && checkchildsum(root->right));
    }
}

//56-----------------------------------------------------------------------------------------------------------------------------------------------

int sumtree(struct treenode *root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 1;

    int lsum = 0,rsum = 0;

    if(root->left)
        lsum = findsum(root->left);

    if(root->right)
        rsum = findsum(root->right);

    if((lsum + rsum) == root->info)
        return 1;
    else
        return 0;

    return(sumtree(root->left) && sumtree(root->right));
}

//57-----------------------------------------------------------------------------------------------------------------------------------------------

void diagonalsum(struct treenode *root)
{
    queue <treenode*> q;
    struct treenode *temp;

    q.push(root);

    while(1)
    {
        int size = q.size();
        if(size == 0)
            break;

        int sum = 0;
        while(size > 0)
        {
            temp = q.front();
            q.pop();

            while(temp != NULL)
            {
                sum = sum + temp->info;

                if(temp->left)
                    q.push(temp->left);

                temp = temp->right;
            }

            size--;
        }
        cout<<sum<<"   ";
    }
}

//58-----------------------------------------------------------------------------------------------------------------------------------------------

int identical(struct treenode *main , struct treenode *sub)
{
    if(main == NULL && sub == NULL)
        return 1;

    if(main == NULL || sub == NULL)
        return 0;

    return((main->info == sub->info) && identical(main->left , sub->left) && identical(main->right , sub->right));
}

int subtree(struct treenode *main , struct treenode *sub)
{
    if(sub == NULL)
        return 1;

    if(main == NULL)
        return 0;

    if(identical(main , sub))
        return 1;

    return(subtree(main->left , sub) || subtree(main->right , sub));
}

//59-----------------------------------------------------------------------------------------------------------------------------------------------

vector <int> nodes;
int index=0;

void getallnodes(struct treenode *root)
{
    if(root == NULL)
        return;

    getallnodes(root->left);
    nodes.push_back(root->info);
    getallnodes(root->right);
}

//60-----------------------------------------------------------------------------------------------------------------------------------------------

int maxsum=0;
int getmaxsumleaf(struct treenode *root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return(root->info);

    int l = getmaxsumleaf(root->left);
    int r = getmaxsumleaf(root->right);

    if(root->left != NULL && root->right != NULL)
    {
        if( (l + r + root->info) > maxsum)
            maxsum = l + r + root->info;

        return (max(l , r) + root->info);
    }

    return root->info != NULL ? (l + root->info) : (r + root->info);
}



int main()
{
    int data,choice,sum=0,n,i=0,start=0,level;
    vector <int> pre,in;
    struct treenode *root =  NULL;

    while(1)
    {
        cout<<"\n1. Create tree"<<endl;
        cout<<"2. Pre-order traversal"<<endl;
        cout<<"3. In-order traversal"<<endl;
        cout<<"4. Post-order traversal"<<endl;
        cout<<"5. Level-order traversal"<<endl;
        cout<<"6. Find the maximum element"<<endl;
        cout<<"7. Search element in the tree"<<endl;
        cout<<"8. Insert an element"<<endl;
        cout<<"9. Find SIZE of tree"<<endl;
        cout<<"10. Find sum of all nodes"<<endl;
        cout<<"11. Print tree in reverse order(level order reversal)."<<endl;
        cout<<"12. Delete specific node"<<endl;
        cout<<"13. Delete tree"<<endl;
        cout<<"14. Find level of a specific node"<<endl;
        cout<<"15. Calculate height of tree"<<endl;
        cout<<"16. Find deepest node of tree"<<endl;
        cout<<"17. Find number of leaf nodes of tree"<<endl;
        cout<<"18. Find the diameter of the tree"<<endl;
        cout<<"19. Find the maximum sum of the level (sum of the maximum level)"<<endl;
        cout<<"20. Print root-to-leaf node elements"<<endl;
        cout<<"21. Check for root to leaf sum"<<endl;
        cout<<"22. Get the LEFT-view of the tree"<<endl;
        cout<<"23. Get the RIGHT-view of the tree"<<endl;
        cout<<"24. Get the TOP-view of the tree"<<endl;
        cout<<"25. Get the BOTTOM-view of the tree"<<endl;
        cout<<"26. Get boundary nodes of the tree"<<endl;
        cout<<"27. Create mirror-image of the tree"<<endl;
        cout<<"28. Find lowest common ancestor (LCA)"<<endl;
        cout<<"29. Construct binary-tree from In-Order and Pre-Order traversal"<<endl;
        cout<<"30. Find ancestors of a node"<<endl;
        cout<<"31. Print binary tree in zig-zag or spiral order"<<endl;
        cout<<"32. Print vertical order of a binary tree"<<endl;
        cout<<"33. Print the vertical sum of the binary tree"<<endl;
        cout<<"34. Get level wise sum"<<endl;
        cout<<"35. Get maximum width of a binary tree"<<endl;
        cout<<"36. Check if the tree is fold-able or not"<<endl;
        cout<<"37. Create double tree of the given tree"<<endl;
        cout<<"38. Check if tree is balanced or not?"<<endl;
        cout<<"39. Minimum height of the binary tree"<<endl;
        cout<<"40. Check if all leaf nodes are at same level?"<<endl;
        cout<<"41. Find deepest node of left sub-tree"<<endl;
        cout<<"42. Find deepest node of right sub-tree"<<endl;
        cout<<"43. Find deepest odd level node"<<endl;
        cout<<"44. Remove all Nodes which lies on path with less than K length from root to leaf"<<endl;
        cout<<"45. Check if a given sequence is present or not from root to leaf"<<endl;
        cout<<"46. Find parent of an element"<<endl;
        cout<<"47. Find sibling of an element"<<endl;
        cout<<"48. Check if two nodes are siblings or not"<<endl;
        cout<<"49. Distance between two nodes"<<endl;
        cout<<"50. Get level wise average of nodes"<<endl;
        cout<<"51. Serialize the tree"<<endl;
        cout<<"52. De-serialize the tree"<<endl;
        cout<<"53. Check if the tree is BST or not?"<<endl;
        cout<<"54. Convert tree into doubly linked list"<<endl;
        cout<<"55. Check if parent is sum of both children"<<endl;
        cout<<"56. Check if the tree is sum tree or not?"<<endl;
        cout<<"57. Find diagonal sum of the tree"<<endl;
        cout<<"58. Check if given tree is Sub-Tree of Main-Tree or not"<<endl;
        cout<<"59. Check if a sum pair is present or not?"<<endl;
        cout<<"60. Maximum leaf to leaf sum"<<endl;
        cout<<"61. EXIT"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            root=create();
            break;

        case 2:
            cout<<"\nPre-order is : ";
            preorder(root);
            break;

        case 3:
            cout<<"\nIn-order is : ";
            inorder(root);
            break;

        case 4:
            cout<<"\nPost-order is : ";
            postorder(root);
            break;

        case 5:
            cout<<"\nLevel-order is : ";
            levelorder(root);
            break;

        case 6:
            cout<<"\nMaximum element is : "<<FindMax(root);
            break;

        case 7:
            cout<<"\nEnter the element you want to search : ";
            cin>>data;

            if(FindElement(root,data)==1)
                cout<<"\nElement is found\n";
            else
                cout<<"\nElement is not found\n";
            break;

        case 8:
            insertelement(root);
            break;

        case 9:
            cout<<"\nSize of tree is = "<<sizeoftree(root);
            break;

        case 10:
            cout<<"\nSum = "<<findsum(root);
            break;

        case 11:
            cout<<"\nReverse order is : ";
            reversetree(root);
            break;

        case 12:
            cout<<"\nEnter the element you want to delete : ";
            cin>>data;
            deletenode(root, data);
            break;

        case 13:
            deletetree(root);
            cout<<"\nTree is deleted.\n";
            root = NULL;

        case 14:
            {
                level = 1;                                                        //level of root is one
                cout<<"\nEnter element to find its level ";
                cin>>data;
                cout<<"\nRequired level is = "<<findlevel(root , data , level)<<endl;
                break;
            }
        case 15:
            cout<<"\nHeight of the tree is = "<<height(root)<<endl;
            break;

        case 16:
            cout<<"\nDeepest node of the tree is = "<<deepest(root)<<endl;
            break;

        case 17:
            cout<<"\nNumber of leaf nodes are = "<<leafnodes(root)<<endl;
            break;

        case 18:
            cout<<"\nDiameter of the tree (number of nodes in the diameter) is  = "<<diameter(root)<<endl;
            break;

        case 19:
            maxlevelsum(root);
            break;

        case 20:
            cout<<"\nAll root-node to leaf-node paths are : "<<endl;
            root_to_leaf(root);
            break;

        case 21:
            cout<<"Enter the sum to check : ";
            cin>>sum;
            checksum(root,sum);
            break;

        case 22:
            {
                level = 0;
                cout<<"Left view of the tree is : ";
                leftview(root , level);
                break;
            }

        case 23:
            {
                level = 0;
                cout<<"Right view of the tree is : ";
                rightview(root , level);
                break;
            }

        case 24:
            level = 0;
            topview(root,level);
            cout<<"Top view of the tree is : ";
            for(it = HashMap.begin() ; it != HashMap.end() ; it++)
                    cout<< it->second << " ";
            break;

        case 25:
            {
                level = 0;
                int height = 0;
                bottomview(root,level,height);
                cout<<"Bottom view of the tree is : ";
                for(it2 = HashMap2.begin() ; it2 != HashMap2.end() ; it2++)
                        cout<< it2->second.first << " ";
                break;
            }

        case 26:
            printboundarynodes(root);
            break;

        case 27:
            mirrortree(root);
            cout<<"\nMirror image of the tree has been created"<<endl;
            break;

        case 28:
            int n1,n2;
            cout<<"\nEnter the nodes for searching their LCA : ";
            cin>>n1>>n2;
            cout<<"\nLCA for "<<n1<<" and "<<n2<<" is = "<<findlca(root,n1,n2)<<endl;

            //For the other made function
            //struct treenode *temp;
            //cout<<"The LCA of "<<n1<<" and "<<n2<<" is : "<<temp->info<<endl;
            break;

        case 29:
            {
                cout<<"\nEnter the size of the traversal : ";
                cin>>n;

                cout<<"\nEnter the Pre-Order : "<<endl;
                for(i = 0 ; i< n ; i++)
                {
                    cin>>data;
                    pre.push_back(data);
                }

                cout<<"Enter the In-Order : "<<endl;
                for(i = 0 ; i< n ; i++)
                {
                    cin>>data;
                    in.push_back(data);
                }

                int endindex = (pre.size()-1);
                root = createtree( pre , in , start , endindex );
                break;
            }

        case 30:
            cout<<"Enter the node's value (data) for its ancestors : ";
            cin>>data;
            allancestors(root , data);
            break;

        case 31:
            cout<<"The ZigZag order or spiral order is : ";
            zigzag(root);
            break;

        case 32:
            {
                map <int , vector <int> > m;
                map <int , vector <int> > :: iterator it3;
                level=0;
                verticalorder(root , level , m);
                cout<<"Vertical order is : "<<endl;
                for (it3 = m.begin() ; it3 != m.end(); it3++)
                {
                    for (int i=0 ; i < it3->second.size() ; ++i)
                            cout << it3->second[i] << " ";
                    cout << endl;
                }
                break;
            }

        case 33:
            {
                level=0;
                verticalsum(root , level);

                cout<<"\nThe the vertical sum is : ";
                for(it = HashMap.begin() ; it != HashMap.end() ; it++)
                    cout<< it->second << " ";
                break;
            }

        case 34:
            {
                level=1;
                int i=1;
                map <int , int> m;
                map <int , int > :: iterator it3;

                levelsum(root , level , m);

                cout<<"\nThe level wise sum = "<<endl;
                for (it3 = m.begin() ; it3 != m.end(); it3++)
                {
                        cout <<"Sum of level "<<i<<" = "<<it3->second << endl;
                        i++;
                }
                break;
            }

        case 35:
            {
                level=1;
                maximumwidth(root , level);
                int maxwidth;
                it = HashMap.begin();
                maxwidth = it->second;
                for(it = HashMap.begin() ; it != HashMap.end() ; it++)
                {
                    if(maxwidth < it->second)
                        maxwidth = it->second;
                }
                cout<<"\nMaximum width of the binary tree = "<<maxwidth<<endl;
                break;
            }

        case 36:
            if(foldable(root)==true)
                cout<<"The tree is fold-able"<<endl;
            else
                cout<<"The tree is not fold-able"<<endl;
            break;

        case 37:
            doubletree(root);
            cout<<"\nDouble tree is created!"<<endl;
            break;

        case 38:
            {
                int temp = ifBalanced(root);
                if(temp == -1)
                    cout<<"\nUnbalanced tree"<<endl;
                else
                    cout<<"\nBalanced tree"<<endl;
                break;
            }

        case 39:
            level=0;
            minheight(root , HashMap , level);
            it = HashMap.begin();
            cout<<"\nMinimum height on the root : "<<it->second;
            break;

        case 40:
            {
                level=1;
                bool c = check_leaf_level(root , level);
                if(c ==1 )
                    cout<<"\nAll leaf nodes are at same level"<<endl;
                else
                    cout<<"\nAll leaf nodes are not at same level"<<endl;
                break;
            }

        case 41:
            cout<<"\nDeepest node of the left sub - tree is = "<<deepest(root->left)<<endl;
            break;

        case 42:
            cout<<"\nDeepest node of the right sub - tree is = "<<deepest(root->right)<<endl;
            break;

        case 43:
            level = 1;
            deepestoddleaf(root,level);
            cout<<"\nDeepest odd node level is = "<<deepestodd;
            break;

        case 44:
            {
                level=1;
                int k;
                cout<<"\nEnter path length : ";
                cin>>k;
                remove_lesser_node(root , level , k);
                cout<<"\nNodes have been deleted from lesser paths"<<endl;
                break;
            }

        case 45:
            {
                int index=0;
                int i=1;
                int size;
                cout<<"\nEnter size of the sequence : ";
                cin>>size;

                cout<<"Enter the sequence : "<<endl;
                int a[size];
                for(i=0;i<size;i++)
                    cin>>a[i];

                int answer = findpattern(root , a , index ,size);

                if(answer == 1)
                    cout<<"\nThe sequence is present in the tree"<<endl;
                else
                    cout<<"\nThe sequence is not present in the tree"<<endl;

                break;
            }

        case 46:
            cout<<"\nEnter element to find its parent : ";
            cin>>data;
            findparent(root,data);
            break;

        case 47:
            {
                cout<<"\nEnter element to find its sibling : ";
                cin>>data;
                int answer = findsibling(root,data);
                if(answer == 0)
                    cout<<"\nNo sibling is found";
                else
                    cout<<"\nSibling is = "<<answer;
                break;
            }

        case 48:
            {
                cout<<"\nEnter elements : ";
                cin>>data>>n;
                int answer = checksibling(root,data,n);
                if(answer == 1)
                    cout<<"YES they are sibling"<<endl;
                else
                    cout<<"NO they are not sibling"<<endl;
                break;
            }

        case 49:
            {
                int n1,n2;
                cout<<"\nEnter nodes to get their distance : ";
                cin>>n1>>n2;
                int lca = findlca(root,n1,n2);

                struct treenode *temp;
                temp = FindElementnode(root,lca);

                int d1 = distance(temp,n1,0);
                int d2 = distance(temp,n2,0);
                cout<<"\nTotal distance = "<<d1+d2<<endl;
                break;
            }

        case 50:
            {
                level=1;
                map <int , int> m;
                map <int , int > :: iterator it3;
                levelsum(root , level , m);

                maximumwidth(root , level);
                it = HashMap.begin();

                cout<<"\nThe level wise average = "<<endl;
                for (it3 = m.begin() ; it3 != m.end(); it3++)
                {
                        cout<<(it3->second)/(it->second)<< endl;
                        it++;
                }
                break;
            }

        case 51:
            serialize(root,pre);
            cout<<"Serialize form of the tree is = ";
            for(int i=0 ; i < pre.size() ; i++)
                cout<<pre[i]<<"  ";
            break;

        case 52:
            {
                int n;
                cout<<"Enter size of the data : ";
                cin>>n;
                int arr[n];
                cout<<"\nEnter pre-order serialized data : ";
                for(int i=0 ; i<n ; i++)
                    cin>>arr[i];

                treenode *temp = deserialize(arr );
                cout<<"\nThe tree has been formed."<<endl;
                cout<<"Level order traversal of the tree is : ";
                levelorder(temp);
                break;
            }

        case 53:
            {
                int res = isBST(root);
                if(res == 0)
                    cout<<"\nTree is not a BST"<<endl;
                else
                    cout<<"\nTree is a BST"<<endl;

                break;
            }

        case 54:
            {
                convert(root);

                struct treenode *temp = head;
                while (temp!=NULL)
                {
                    cout << temp->info << " ";
                    temp = temp->right;
                }
                break;
            }

        case 55:
            {
                int ans = checkchildsum(root);
                if(ans == 0)
                    cout<<"Every parent is not sum of its children"<<endl;
                else
                    cout<<"Every parent is sum of its children"<<endl;
                break;
            }

         case 56:
            {
                int ans = sumtree(root);
                if(ans == 0)
                    cout<<"Tree is a sum tree"<<endl;
                else
                    cout<<"Tree is not a sum tree"<<endl;
                break;
            }

         case 57:
            cout<<"\nDiagonal sum = ";
            diagonalsum(root);
            break;

         case 58:
            {
                struct treenode *sub = create();
                int ans = subtree(root , sub);

                if(ans == 0)
                    cout<<"\nIt is not a sub tree"<<endl;
                else
                    cout<<"\nIt is a sub tree"<<endl;
                break;
            }

        case 59:
            {
                int flag = 0;
                cout<<"Enter the sum : ";
                cin>>data;

                getallnodes(root);
                for(int i=0 ; i < nodes.size() ; i++)
                {
                    if(flag == 1)
                        break;
                    else
                    {
                        for(int j=i ; j < nodes.size() ; j++)
                        {
                            if(nodes[i] + nodes[j] == data)
                            {
                                cout<<"Sum is present"<<endl;
                                flag=1;
                                break;
                            }
                        }
                    }
                }

                break;
            }

        case 60:
            cout<<"Maximum sum = "<<getmaxsumleaf(root);
            break;

        case 61:
            exit(0);
            break;

        default:
            cout<<"\nINVALID CHOICE..."<<endl;
        }
    }
    return 0;
}

