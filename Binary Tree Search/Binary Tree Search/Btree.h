//
//  Btree.h
//  Binary Tree Search
//
//  Created by Julianne Salah on 11/21/15.
//  Copyright (c) 2015 Julianne Salah. All rights reserved.
//

#ifndef Binary_Tree_Search_Btree_h
#define Binary_Tree_Search_Btree_h

//////////////////////////////////////////////////////////////////////////////////
/////////////////////////// INT class & implementation ///////////////////////////
//////////////////////////////////////////////////////////////////////////////////

struct INT
{
public:
    int * _data;
    

    INT()
    {
        _data = nullptr;
    }
    
    INT(int data)
    {
        _data = new int(data);
    }
    
    ~INT()
    {
        if(_data != NULL)
            delete _data;
    }
    
    void operator=(INT &rhsoj);
    bool operator==(INT  *&rhsoj);
    bool operator<(const INT&) const;
    bool operator>(const INT&) const;
};

void INT::operator=(INT &rhsoj)
{
    if(_data != NULL)
        delete _data;
    _data = new int(*(rhsoj._data));
}

bool INT::operator==(INT *&rhsoj)
{
    if (_data == rhsoj->_data)
        return true;
    else
        return false;
}


bool INT::operator<(const INT& rhsoj) const
{
    if (*(_data) < *(rhsoj._data))
        return true;
    else
        return false;
}

bool INT::operator>(const INT& rhsoj) const
{
    if (*(_data) > *(rhsoj._data))
        return true;
    else
        return false;
}


//////////////////////////////////////////////////////////////////////////////////
/////////////////////////// BNode class & implementation /////////////////////////
//////////////////////////////////////////////////////////////////////////////////

template<typename T>
class	BNode{
public:
    
    //	data	members
    T *data;
    BNode	*left;
    BNode	*right;

    
    BNode()
    {
        data = nullptr;
        left = nullptr;
        right = nullptr;
    }
    
    BNode(const T&, BNode<T>* left = 0, BNode<T>* right = 0);
    bool operator>(const BNode<T> );
    bool operator<(const BNode<T> );

    
    ~BNode()
    {
        delete data; //destructor
    }
    
    
    
 };



template<typename T>
bool BNode<T>::operator<(const BNode<T> rhsoj)
{
    if (*(this->data) < *(rhsoj.data))
        return true;
    else
        return false;
}

template<typename T>
bool BNode<T>::operator>(const BNode<T> rhsoj)
{
    if (*(this->data) > *(rhsoj.data))
        return true;
    else
        return false;
}

template <typename T>
BNode<T>::BNode(const T&  value,  BNode<T> *ptrleft, BNode<T> *ptrright)
{
    data = new T(value);
    left = ptrleft;
    right = ptrright;
    
}



//////////////////////////////////////////////////////////////////////////////////
//////////////////// binary tree class & implementation //////////////////////////
//////////////////////////////////////////////////////////////////////////////////


template<typename	TreeType>
class	BinaryTree
{
public:
    BNode<TreeType>	*_root;
    size_t	count;
    
    BinaryTree()
    {
        _root = nullptr;
        count = 0;
    }

    ~BinaryTree()
    {
        clear(_root);//destructor
    }
    

    size_t size() const
    {
        return count;
    }


    void printInorderTraversal();
    void printPreorderTraversal();
    void printPostorderTraversal();

    void clear(BNode<TreeType>* node);
    BNode<TreeType>* findSuccessor(BNode<TreeType> *&root);
    void loaddata(std::string file);
    
    int numberofNodes(BNode<TreeType> *&root);
    int heightoftree(BNode<TreeType> *&root);
    
    
    void Insert(TreeType &data);
    void Delete(TreeType &data);
    bool findpublic(TreeType &data);
    bool _findpublic(TreeType value);
    
    
BinaryTree& operator = (BinaryTree&& rhs)
    {
        if(&rhs == this)
            return *this;
        clear();
        _root = rhs.root;
        count = rhs.count;
        rhs.root = nullptr;
        rhs.count = 0;
        return *this;
    }
  
    
private:
    void InsertPrivate(BNode<TreeType> *&root, const TreeType &data);
    void DeletePrivate(BNode<TreeType> *&root, const TreeType &data);
    void printInorderTraversalPrivate(BNode<TreeType> *&node);
    void printPreorderTraversalPrivate(BNode<TreeType> *&node);
    void printPostorderTraversalPrivate(BNode<TreeType> *&node);
    bool find(BNode<TreeType> *&root, int data);
    bool _find(BNode<TreeType> *&node, TreeType value);
    
};



///////////////////////////binary tree insert///////////////////////////
template<typename	TreeType>
void BinaryTree<TreeType>::Insert(TreeType &data)
{
    InsertPrivate(_root, data);
}

template<typename	TreeType>
void BinaryTree<TreeType>::InsertPrivate(BNode<TreeType> *&root, const TreeType &data)
{
    
    
    if(root == NULL)
    {
        root = new BNode<TreeType>(data);
        count++;
    }
    else
    {
        
        if(*(root->data->_data) < *(data._data))
            InsertPrivate(root->right, data);
        else if(*(root->data->_data) > *(data._data))
            InsertPrivate(root->left, data);
        else
            std::cout<< "Warning, duplicate value, ignoring" << std::endl;
        
    }
    
   return;
   
}
///////////////////////////binary tree insert///////////////////////////



///////////////////////////binary tree delete///////////////////////////
template<typename	TreeType>
void BinaryTree<TreeType>::Delete(TreeType &data)
{
    DeletePrivate(_root, data);
}

template<typename	TreeType>
void BinaryTree<TreeType>::DeletePrivate(BNode<TreeType> *&root, const TreeType &data)
{
    if(root == nullptr)
    {
        std::cout << "empty already" << std::endl;
        return;
    }
    else if (*(root->data->_data) < *(data._data))
        DeletePrivate(root->right, data);
        
    else if(*(root->data->_data) > *(data._data))
        DeletePrivate(root->left, data);
    
    else if(root->left && root->right)
        //found element
    {
            //replace
        //count--;
            *(root->data->_data) = *(findSuccessor(root->left)->data->_data);
                DeletePrivate(root->left, *(root->data));
        }
        else
        {
            BNode<TreeType>* temp = root;
          
            if (root->left != NULL)
                root = root->left;
            if(root->right != NULL)
                root = root->right;
            delete temp;
            root = nullptr;
        }
    
}


/////////////////////////////binary tree delete//////////////////////////
        


/////////////////////////////binary tree find///////////////////////////
template<typename	TreeType>
bool BinaryTree<TreeType>::findpublic(TreeType &data)
{
    return find(_root, *(data._data));
    
}


template <typename TreeType>
bool BinaryTree<TreeType>::find( BNode<TreeType> *&root, const int data)
{
if(root == nullptr)
{
std::cout<< "not found: " << data << std::endl;
return false;
}
if(*(root->data->_data) < data)
{
return find(root->right, data);
}

else if(*(root->data->_data) > data)
{
return find(root->left, data);
}
else
{
std::cout<< "found: " << *((root->data)->_data) << std::endl;
return true;
}
            }


/////////////////////////////binary tree find////////////////////////////
template <typename TreeType>
bool BinaryTree<TreeType>::_findpublic(TreeType data)
{
    return	_find(_root, data);
}

template <typename TreeType>
bool BinaryTree<TreeType>::_find(BNode<TreeType> *&root, TreeType data)
{
    if (root != NULL)
    {
        if (data > *((root->data)->_data))
            return _find(root->right, data);
        if (data < *((root->data)->_data))
            return _find(root->left, data);
        else
            return true;
    }
    
}
        

        
        
/////////////////////////////printInorderTraversal()/////////////////////
template<typename	TreeType>
void BinaryTree<TreeType>::printInorderTraversal()
{
    printInorderTraversalPrivate(_root);
}

template<typename	TreeType>
void BinaryTree<TreeType>::printInorderTraversalPrivate(BNode<TreeType> *&node)
{
        if (node == NULL)
            return;
        printInorderTraversalPrivate(node->left);
        printf("%d ", *((node->data)->_data));
        printInorderTraversalPrivate(node->right);
      
}
/////////////////////////////printInorderTraversal()/////////////////////

        
/////////////////////////////printPreorderTraversal()/////////////////////
template<typename	TreeType>
void BinaryTree<TreeType>::printPreorderTraversalPrivate(BNode<TreeType> *&node)
{	if (node)	{
        printf("%d ", *((node->data)->_data));
        printPreorderTraversalPrivate(node->left);
        printPreorderTraversalPrivate(node->right);
        }
}

template<typename	TreeType>
void BinaryTree<TreeType>::printPreorderTraversal()
{
    printPreorderTraversalPrivate(_root);
}

/////////////////////////////printPreorderTraversal()/////////////////////
    

/////////////////////////////printPostorderTraversal()/////////////////////
template<typename	TreeType>
void BinaryTree<TreeType>::printPostorderTraversal()
{
    printPostorderTraversalPrivate(_root);
}

template<typename	TreeType>
void BinaryTree<TreeType>::printPostorderTraversalPrivate(BNode<TreeType> *&node)
{if (node)	{
            printPostorderTraversalPrivate(node->left);
            printPostorderTraversalPrivate(node->right);
            printf("%d ", *((node->data)->_data));
        }
}
/////////////////////////////printPostorderTraversal()/////////////////////



/////////////////////////////FindSuccessor/////////////////////////////////
template<typename TreeType>
BNode<TreeType>* BinaryTree<TreeType>::findSuccessor(BNode<TreeType> *&root)
{
    if(root != nullptr)
        while(root->right != NULL)
            root = root->right;
            return root;
}
/////////////////////////////FindSuccessor/////////////////////////////////



/////////////////////////////height of tree/////////////////////////////////
template<typename TreeType>
int BinaryTree<TreeType>::heightoftree(BNode<TreeType> *&root)
{
    int leftheight, rightheight;
    
    if (root==NULL)
        return 0;
    else{
        leftheight = heightofTree(root->left);
        rightheight = heightofTree(root->right);
        
        if (leftheight > rightheight)
            return (leftheight + 1);
        else
            return(rightheight + 1);
        
    }
}
/////////////////////////////height of tree/////////////////////////////////




////////////////////////////////clear tree///////////////////////////////////
template<typename TreeType>
void BinaryTree<TreeType>::clear(BNode<TreeType>* node)
{
    if (node == nullptr)
        return;
    
    else if(node)
    {
        if(node->left)
            clear(node->left);
        if(node->right)
            clear(node->right);
        delete node;
    }
}
////////////////////////////////clear tree///////////////////////////////////


//////////////////////////////Load Function ///////////////////////////////////
template<typename TreeType>
void BinaryTree<TreeType>::loaddata(std::string file)
{
    std::ifstream inputfile(file);
    int info;
    while (inputfile>>info)
    {
        
        TreeType * temp = new TreeType(info);
        Insert(*temp);
        
    }
}
//////////////////////////////Load Function ///////////////////////////////////


#endif
