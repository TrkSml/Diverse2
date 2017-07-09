#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <signal.h>
#include<boost/range/numeric.hpp>
#include <queue>


struct tree{
    int val ;
    tree* right;
    tree* left ;
    tree* parent ;
};

using namespace std ;

void insert_element(tree* node, unsigned long int el){

        if(!node->val){
            node->val=el;
            node->right=NULL;
            node->left=NULL ;
            node->parent=NULL;
        }
        else {

            if(el==node->val){} ;
            if(el<node->val){
                if (node->left){
                    insert_element(node->left,el);
                }
                else{

                    node->left=new tree;
                    node->left->val=el;
                    node->left->right=NULL;
                    node->left->left=NULL;
                    node->left->parent=new tree ;
                    node->left->parent=node ;
                }

            }
            else
            {
                if (node->right){
                    insert_element(node->right,el);
                }
                else{
                    node->right=new tree;
                    node->right->val=el;
                    node->right->right=NULL;
                    node->right->left=NULL;
                    node->right->parent=new tree ;
                    node->right->parent=node ;

                }

            }
        }

    }



void inorder(tree* node)
{

    if (node==NULL){ // end the recursion if node == nullptr
    std::cout << "end" << "\n";
       return;
   }
    inorder(node->left);            // display the left subtree
    std::cout << node->val << "\n"; // display the current node
    inorder(node->right);           // display the right subtree
}

tree* insert_elements_user(){

    tree* root=new tree ;
    char ok;
    unsigned long int el ;

    std::cout << " integer please : " << "\n";
    std::cin >> el;
    root->val=el;
    root->right=NULL;
    root->left=NULL;
    std::cout << "Do you wish to continue ? N for No and Y for Yes " << "\n";
    std::cin >> ok ;

    while(toupper(ok)!='N'){

        unsigned long int el ;
        std::cout << " integer please : " << "\n";
        std::cin >> el;
        insert_element(root,el);
        std::cout << "Do you wish to continue ? N for No and Y for Yes " << "\n";
        std::cin >> ok;

    }

    return root ;

}

void printtreenode(tree *root)
    {

    // if(root == NULL)
    //   return;
    if(root){
    printtreenode(root->left);
    std::cout << root->val << "\n";
    printtreenode(root->right);
        }
    }

vector<int> concat(vector<int> v1,vector<int> v2){
    v1.insert(v1.end(),v2.begin(),v2.end());
    return v1 ;
}

std::vector<int> int_to_vect(int el){
    std::vector<int> vectel(1,el);
    return vectel;
}

int countNodes( tree *root ) {

        if (root == NULL)
           return 0;
        else {
           int count = 1;
           count += countNodes(root->left);
           count += countNodes(root->right);
           return count;
        }
     } // end countNodes()



bool exists(unsigned long int el,tree *root){

    if(root){
    if(el==root->val)
        return 1;

    if (el<root->val)
        return exists(el,root->left);

    else
        return exists(el,root->right);
    }
    else
    return 0 ;
}

tree* searchNode(unsigned long int el,tree *root){

    if(root){
    if(el==root->val)
        return root;

    if (el<root->val)
        return searchNode(el,root->left);

    else
        return searchNode(el,root->right);
    }
    else
    return NULL ;
}

tree* searchParentNode(unsigned long int el,tree *root){

    if (exists(el,root))
        return searchNode(el,root)->parent;
    else{

        tree* null_struct=new tree ;
        null_struct->val=-1 ;
        null_struct->left=NULL ;
        null_struct->right=NULL;
        null_struct->parent=NULL;
        return null_struct ;
    }
}


unsigned max(unsigned a,unsigned b)
{
	return (a>=b)? a : b ;
}

unsigned min(unsigned a,unsigned b)
{
	return (a<=b)? a : b ;
}


int max_depth(tree* root){

    if(!root) {
    return 0 ;
    }
    else{
    return 1+max(max_depth(root->left),max_depth(root->right));
    }

}

int min_depth(tree* root){

    if(!root) {
    return 0 ;
    }
    else{
    return 1+min(min_depth(root->left),min_depth(root->right));
    }

}

void delete_tree(tree* root){

    if(root){

        delete_tree(root->left);
        delete_tree(root->right);
        delete(root) ;
    }
    delete root;

}


void displayVector(vector<int> vect){
    vector<int>::iterator itg;
    for(itg = vect.begin(); itg != vect.end(); itg++)
    {
        std::cout << *itg << " ";
    }
    std::cout << "\n";
}

void displayArray(int a[],tree* node){
    for (int i = 0; i < countNodes(node); ++i)
    {
        std::cout << a[i] << "  ";
    }
    std::cout << "\n";
}


const char* displayBool(int assertion){
    if(assertion==1){
        return "True";
    }
    else{
        return "False" ;
    }
}

void ouch(int sig)
{
    std::cout << "Ouch got a signal : "<< sig << " ." << "\n";
}

vector<int> TreeToSortedVector(tree *node){
    static vector<int> outcome ;
    if(node){
            TreeToSortedVector(node->left);
            outcome.push_back(node->val);
            TreeToSortedVector(node->right);
            }

    return outcome ;
        }

/*output an array-version of the tree*/
int* TreeToArray(tree *node){
    static int *arr=new int[countNodes(node)] ;
    static int pos=0 ;

        if(node){
                arr[pos++]=node->val;
                TreeToArray(node->left);
                TreeToArray(node->right);
                }
     return arr ;
    }

typedef struct double_vect {
    vector<int> odd;
    vector<int> even ;
};

/*Separate the elements to even and odd ones*/
 double_vect TreeToOddEven(tree *node){

    static double_vect all ;
    static vector<int> odd_vect;
    static vector<int> even_vect ;

    if(node){
            if (node->val%2)
             odd_vect.push_back(node->val);

            else
            even_vect.push_back(node->val);

            TreeToOddEven(node->left);
            TreeToOddEven(node->right);
        }

    all.odd=odd_vect;
    all.even=even_vect;

    return all;
        }

vector<int> PathFinder(int aim,tree* root){
    static vector<int> path;
    if (exists(aim,root)){
        if(searchParentNode(aim,root)){
            tree *parent=searchParentNode(aim,root);
            path.push_back(parent->val);
            PathFinder(parent->val,parent);
        }
    }
    return path ;
}

int SumVector(std::vector<int> vector){

    /* usual way

    unsigned long int sum_of_path_elems=0;
    for (int i = 0; i <v.size() ; ++i)
    sum_of_path_elems += v[i];
    return sum_of_path_elems;

    */

    return boost::accumulate(vector, 0);

}

/* print out the children and the parent for each node of the tree */
void displayDependenciesNode(tree* node){

    if(node==NULL) std::cout << "node is NULL" << "\n";
    else{

    if(node->left) std::cout << "node with value : "<<node->val<< \
        " has left node with value "<< node->left->val << "\n";

    if(node->right) std::cout << "node with value : "<<node->val<< \
            " has right node with value "<< node->right->val << "\n";

    if(node->parent) std::cout << "node with value : "<<node->val<< \
        " has parent node with value "<< node->parent->val << "\n";
        }
    std::cout << "\n";
}

/* print out the children and the parent for all the nodes of the tree */
void displayDependencies(tree* root){

    if(root){
        displayDependenciesNode(root);
        displayDependencies(root->left);
        displayDependencies(root->right);

    }
}



/** Stand By **/
void deleteKey(int el,tree* root){

    tree* node=searchNode(el,root);

    if(node->val==root->val){}
    else{
    if(node->right==NULL && node->left){

        if(node->val>node->parent->val){
            node->parent->right=node->left;
            delete node ;
        }
        else {
            node->parent->left=node->left;
            delete node ;
        }
    }

    else if(node->right && node->left==NULL ){

        if(node->val>node->parent->val){
            node->parent->right=node->right;
            delete node ;
        }

        else {

            node->parent->left=node->right;
            delete node ;
        }
    }

    else if(node->right && node->left ){

        if(node->val>node->parent->val){

            node->parent->right=node->right ;
            tree* current=node;
            while(current->right) current=current->right;
            while(current!=node)

            {
                current->left=current->parent->left;
                current->left->parent=current->parent ;
                current=current->parent;
            }

            //let us fix the rest ;;

            node->right->parent=node->parent;
            node->left->parent=node->right ;

            delete node;
        }
        else {

            node->parent->left=node->right ;
            tree* current=node;
            while(current->right) current=current->right; // Going all the way down to the bottom node
            while(current!=node)
            {

                // replacing each node with the parent node
                // and translating it to the upper level
                // in order to perfectly replace the deleted key

                current->left=current->parent->left;
                current->left->parent=current->parent ;
                current=current->parent;

            }

            node->right->parent=node->parent;
            node->left->parent=node->right ;

            delete node;

        }

    }

    else if(node->right==NULL && node->left==NULL ){
        if(node->parent->val<node->val){
            node->parent->right=NULL;
            delete node;

        }else {

            node->parent->left=NULL;
            delete node;

        }
    }
  }
}

// Construct a mirror of the current tree
// which swaps all the right and left elements

void mirror(tree* root){
    if(root->right && root->left){
        tree* tmp=root->right;
        root->right=root->left;
        root->left=tmp;

        mirror(root->left);
        mirror(root->right);

    }
}

// maximum value within the whole tree
int max_value(tree* root){
    if (root->right==NULL) return root->val;
    return max_value(root->right);
}

// minimum value within the whole tree
int min_value(tree* root){
    if (root->left==NULL) return root->val;
    return min_value(root->left);
}

void DrawTreeInorder(tree* root){

    const char star='*';
    static int push=0;
    push ++ ;
    if(root)
    {

        if(root->left)
        {
            DrawTreeInorder(root->left);
        }
        std::cout << std::string(push, star) << root->val<< "\n";
        if(root->right)
        {
            DrawTreeInorder(root->right);
        }

   }
}



void diagonalTreePrint(tree* root){

    std::queue<tree*> Qu;
    Qu.push(root);
    Qu.push(NULL);
    //std::cout << "Debug size : "<<Qu.size() << "\n";

    while(Qu.size()){
        tree* p;
        p=Qu.front();
        Qu.pop() ;
        //if(p!=NULL) std::cout << "Debug value: "<< p->val <<"\n";
        //std::cout << "Debug size : "<<Qu.size() << "\n";
        if(p==NULL){

            Qu.push(NULL);
            p=Qu.front();
            Qu.pop();
            //if(p!=NULL) std::cout << "Debug value: "<< p->val <<"\n";
            if(p==NULL)break;
        }
        //std::cout << "Debug size : "<<Qu.size() << "\n";

        while(p!=NULL){

            std::cout << p->val <<"--->";
            if(p->left)
                Qu.push(p->left);
            p=p->right ;

        }
        std::cout <<"\n";
    }
}


void treeLevelByLevelTwoQueues(tree* root){
    // Print LEvel by level tree using two queues

    std::queue<tree*> q1;
    std::queue<tree*> q2;
    q1.push(root);
    tree* node=root;

    while(q1.size() || q2.size()){
        if(q1.front()!=root) std::cout << "\n";
        while(q1.size()){
        tree* current;
        current=q1.front();
        q1.pop();
        if(current->left) q2.push(current->left);
        if(current->right)q2.push(current->right);
        std::cout << current->val << " ";

        }

        std::cout <<"\n";

        while(q2.size()){

        tree* current;
        current=q2.front();
        q2.pop();
        if(current->left) q1.push(current->left);
        if(current->right)q1.push(current->right);
        std::cout << current->val << " ";

        }

    }
    std::cout <<"\n";
}

void treePrintQueueDelimeter(tree* root){

    std::queue<tree*> Qu;
    Qu.push(root);
    Qu.push(NULL);

    while(Qu.size()){
        tree* p;
        p=Qu.front();

        if(p)
        {
            if(p->left) Qu.push(p->left);
            if(p->right) Qu.push(p->right);
            std::cout << p->val << " ";
            Qu.pop() ;
        }

        if(p==NULL){

            Qu.push(NULL);
            Qu.pop();
            tree* p_test ;
            p_test=Qu.front();
            if(p_test==NULL)break;
            std::cout << "\n";

            }
        }
        std::cout << "\n";
    }

void treePrintQueueCounter(tree* root){
    std::queue<tree*> Qu;
    Qu.push(root);
    int countLevel, currentCount,current;

    countLevel=1;
    currentCount=0 ;

    while((currentCount || countLevel) && Qu.size()){

        tree* node=Qu.front();
        if(node){
            if(node->left) {
                Qu.push(node->left);
                currentCount++ ;
                }
            if(node->right) {
                Qu.push(node->right);
                currentCount++ ;
                }
        }

        std::cout << node->val << " ";
        countLevel-- ;
        Qu.pop();

        if(!countLevel){
            std::cout << "\n" ;
            countLevel=currentCount ;
            currentCount=0 ;
        }
      }
    }

int main(){

    /*
    // the next part deals with segmentation fault
    struct sigaction act;
    act.sa_handler = ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, 0);
    */

    tree *root= new tree;
    insert_element(root,10);
    insert_element(root,58);
    insert_element(root,25);
    insert_element(root,7);
    insert_element(root,951);
    insert_element(root,75);
    insert_element(root,35);
    insert_element(root,98);
    insert_element(root,43);
    insert_element(root,775);
    insert_element(root,32);
    insert_element(root,90);
    insert_element(root,73);
    insert_element(root,1029);
    insert_element(root,23);
    insert_element(root,1000);
    insert_element(root,1030);
    insert_element(root,3);
    insert_element(root,9);

    /*
        ...
        What you want to do
        ...

    */

return 0;
}
