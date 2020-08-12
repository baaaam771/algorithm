#include "cNode.h"
#include <iostream>
using namespace std;

template <typename T>
class cBinarySearchTree {
   friend class cNode<T>;
public:
   cBinarySearchTree();
   ~cBinarySearchTree();
   void treeInsert(T x);
   void treeDelete(T x);
   void treePrint();
private:
   cNode<T>* treeInsert(cNode<T>* t, T x);
   void treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p);
   cNode<T>* deleteNode(cNode<T>* r);
   void treePrint(cNode<T>* t, int step);
   cNode<T>* root;
};

template <typename T>
cBinarySearchTree <T>::cBinarySearchTree() {
   root = NULL;
}

template <typename T>
cBinarySearchTree <T>::~cBinarySearchTree() {
}

template <typename T>
void cBinarySearchTree <T>::treePrint() {
   treePrint(root, 0);
}

template <typename T>
void cBinarySearchTree <T>::treeInsert(T x) {
   root = treeInsert(root, x);
}

template <typename T>
void cBinarySearchTree<T>::treeDelete(T x) {
   cNode<T>* r = root;
    cNode<T>* p = 0;
 
    while(r != 0) {
        if(r->key == x) 
            break;
        p = r;
        if(x < r->key) 
            r = r->left;
        else
            r = r->right;
    }
    if (r)       treeDelete(root, r, p);
}

template <typename T>
cNode<T>* cBinarySearchTree <T>::treeInsert(cNode <T>* t, T x) {
   if(t == NULL) {
      cNode<T> *r = new cNode<T>(x);
      return r;
   }
   if(x < t->key) {
      t->left = treeInsert(t->left, x);
      return t;
   }
   else{
      t->right = treeInsert(t->right, x);
      return t;
   }
}

template <typename T>
void cBinarySearchTree <T>::treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p) {
   if(r == t)
        root = deleteNode(t);
   else if(r == p->left)
      p->left = deleteNode(r);
   else
      p->right = deleteNode(r);
}

template <typename T>
cNode<T>* cBinarySearchTree <T>::deleteNode(cNode<T>* r) {
   if(r->left == NULL && r->right == NULL) 
      return NULL;
   else if(r->left == NULL && r->right != NULL) 
      return r->right;
   else if(r->left != NULL && r->right == NULL) 
      return r->left;
   else {
      cNode<T>* s = r->right;
      cNode<T>* parent = r;
      while(s->left != NULL) {
         parent = s;
         s = s->left;
      }
      r->key = s->key;
      if(s == r->right) 
         r->right = s->right;
      else 
         parent->left = s->right;
      return r;
   }
}

template <typename T>
void cBinarySearchTree <T>::treePrint(cNode<T>* t, int step) {
   if (t != NULL) {
      for(int i = 0; i < step; i++) 
         cout << "    ";
      cout << t->key << endl;
      step++;
      treePrint(t->left, step);
      treePrint(t->right, step);
   }
}
