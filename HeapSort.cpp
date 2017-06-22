// Heap Sort
// using only linked lists
//
// @author: Tarek Samaali
//

#include <iostream>
#define LENGTH_LL 12

struct node
{
    int value;
    node *next;
};

node* create_List(){

    node *root;
    root=new node ;
    std::cout << " a new value ? : " << "\n";
    int first_val;
    std::cin >> first_val;
    root->value=first_val;
    root->next=0 ;
    int count=1 ;
    
    while(count<LENGTH_LL){

        node* current ;
        current=root ;
        int val ;
        std::cout << " a new value ? : " << "\n";
        std::cin >> val;

        if(current){
            while(current->next){
                current=current->next ;
            }
        }

        current->next=new node ;
        current=current->next ;
        current->value=val ;
        current->next=0 ;
        count++ ;
    }
    return root ;

}

void Affiche_List(node *root){

    node *current;
    current=root ;
    int i=0;
    
    while(current){
    
        std::cout << "value number "<< i << ":   ";
        std::cout << current->value << "\n";
        current=current->next ;
        std::cout << "\n";
        i++ ;

        }
    }

void affiche(node *root){
    
        node *current;
        current=root ;
        int i=0;
        while(current){
            std::cout << current->value << " ";
            current=current->next ;
            i++ ;

            }
        std::cout << "\n";
        }

int List(node *root,int index){

    int result;
    int count=0;
    node *current;
    current=root ;
    while(count < index){
    
        if(!current){
            std::cout << "Error !" << "\n";
        }
        current=current->next;
        count++;
    }
    
    result=current->value;
    return result ;
}

int len(node* root){

    if(root==NULL) return 0 ;
    int length=0;
    node* current=root;
    while(current){
        length++;
        current=current->next;
    }
    
    return length;
}

int right_child(node *root,int index){

    int index_right=2*index+2;
    int result ;
    (index_right>LENGTH_LL) ? result=-1 : result=List(root,index_right);
    return result ;
}

int left_child(node *root,int index){

    int index_left=2*index+1;
    int result ;
    (index_left>LENGTH_LL) ? result=-1 : result=List(root,index_left);
    return result ;
}


int find_parent_index(node *root,int index){

    if(index==0){
        return 0;
    }
    else{
        return (index-1)/2;
    }
}


int find_parent_element(node *root,int index){

    return List(root,find_parent_index(root,index));
}


void insert_and_replace(node *root ,int el,int position){

    if(position>LENGTH_LL){
            std::cout << "ERROR !" << "\n";
        }
    int count=0;
    node *current;
    current=root ;
    while(count<position){
        current=current->next;
        count++;
    }
    current->value=el;

}


void exchange(node *root,int pos1,int pos2){

    int element1=List(root,pos1);
    int element2=List(root,pos2);
    insert_and_replace(root,element1,pos2);
    insert_and_replace(root,element2,pos1);

}


node* withoud_begin(node *root, int end){

    node* main_result=new node;
    node* result=main_result ;
    node* current=root;
    int count=0;
    if (end==0){
        result->value=current->value;
        result->next=NULL ;
    }
    else {

        while(count<(end-1)){

            result->value=current->value;
            result->next=new node ;
            current=current->next ;
            result=result->next;
            count++ ;
            }
        result->value=current->value;
        result->next=NULL;
    }

    return main_result;
}


node* withoud_end(node *root, int begin){

    node* main_result=new node;
    node* result=main_result ;
    node* current=root;
    int count=0;
    while(count<begin){
        current=current->next;
        count++;
    }
    while(current){
        result->value=current->value;
        current=current->next;
        if(current){
            result->next=new node ;
            result=result->next;
        }
        else{
            result->next=NULL;
        }
    }

    return main_result;

}


node* list_extractor(node *root,int begin, int end){

    node* current1=root;
    int count=0 ;

    if(end==-1){
        return withoud_end(root,begin);
    }

    if(begin==-1){
        return withoud_begin(root,end);
    }

    while(count<begin){
        if(begin>LENGTH_LL || end>LENGTH_LL){
            std::cout << "ERROR !" << "\n";
        }
        current1=current1->next;
        count++;
    }


    node* main_list_result=new node;
    node* list=main_list_result;
    list->value=current1->value;
    current1=current1->next;

    while(count<end){
    
        list->next=new node;
        list=list->next;
        list->value=current1->value;
        current1=current1->next;
        count++;
    }

    return main_list_result;

}

node* list_concatenate(node* list1,node* list2){

    if(!list1) return list2;
    if(!list2) return list1;

    node* current=list1;
    while(current->next){
        current=current->next;
    }
    current->next=list2;
    return list1;
}

void partial_heap(node* root,int index){

    int count=index;
    while(count>=0){
        int element=List(root,count);
        if (element>find_parent_element(root,count)){
            int parent_position=find_parent_index(root,count);
            exchange(root,parent_position,count);
            count=parent_position;
        }
        else{
            break;
        }
    }
}

node* build_max_heap(node* root){

    for (int i = 1; i <= len(root)-1; i++)
    {
        partial_heap(root,i);
    }
    return root;
}

node* to_node(int el){

    node* result=new node;
    result->value=el;
    result->next=NULL;
    return result;
    
}

node* heap_sort(node* root){

    int count=len(root);
    node* result=NULL;
    node* array=list_extractor(root,-1,count);
    while(count>=1){
        affiche(array);
        count--;
        array=build_max_heap(array);
        node* max=to_node(List(array,0));
        result=list_concatenate(max,result);
        array=list_extractor(array,1,-1);

    }
    return result;
}

int main()
{
    node *root1 ;
    node *result ;
    root1=create_List();
    root2=heap_sort(root1);
    affiche(root2);

  return 0 ;
}
