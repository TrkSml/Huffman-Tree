#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Node{
    int val ;
    int occ ;
    struct Node* next ;
    //struct Node* previous;
}Node;

// typedef struct NodeBis{
//     int occ ;
//     struct NodeBis* next ;
//     //struct Node* previous;
// }NodeBis;

typedef Node* list;


typedef struct tree{
  struct Node* root ;
  struct tree* left;
  struct tree* right;
}Tree;


typedef struct list{
    list head;
    list tail;
    //struct list previous;
}listht ; // list with head and tail

typedef struct equival{
  struct Node* nodeattr;
  struct Tree* treeattr;
  struct equival* next;
}Equival;
//typedef list list_type;

void insert_element(list** l,int el){

    if(*l==NULL){
      list current=(list)malloc(sizeof(Node));
      current->val=el ;
      current->occ=1 ;
      current->next=NULL ;
      //current->previous=NULL ;
      *l=current ;
      printf("First element added successfully ..  \n\n");
    }
    else {


      list current=*l ;
      bool change=false ;
      while(current->next){

            if(el==current->val){
            current->occ++ ;
            change=true ;
            break;
          }

          //else{
          current=current->next ;
          //}
        }

        if(el==current->val && !change){
          current->occ++ ;
        }
        else{

          if(current->next==NULL){

            list new_current=(list)malloc(sizeof(Node));
            new_current->val=el;
            new_current->occ=1 ;
            new_current->next=NULL ;
            //new_current->previous=current ;
            current->next=new_current;


      }
    }
  }

}

void display_surroundings(list* l){
  list current=*l;
  printf("Printing the elements of the stack : \n");
  while(current){
      printf("current Node : (val: %d,occ: %d ) \n",current->val,current->occ);
      if(current->next) printf("[next :(val: %d ,occ: %d )] \
      \n\n",current->next->val,current->next->occ);

      else if(!current->next) printf("[next : NULL ]\
       \n\n");

      else printf("[next : (val: %d ,occ: %d ) ] \
      \n\n",current->next->val,current->next->occ);
      current=current->next;
  }
  printf("\n");

}

void sort_list_by_values(list *l){
    list current=*l ;

    while(current->next ){
      list crawler=current->next;
      // printf("%p\n",crawler);
      // printf("%p\n",current);
      while(crawler){

        if(crawler->occ<current->occ){

        int tmp_occ=crawler->occ;
        crawler->occ=current->occ;
        current->occ=tmp_occ;

        int tmp_val=crawler->val;
        crawler->val=current->val;
        current->val=tmp_val;


        }
        crawler=crawler->next ;

      }
      current=current->next ;
    }
}




    void swap_Node(Node** first,Node** second,Node** l)
        {

            Node* tmp1=*first;
            Node* tmp2=*second;

            Node *current1=*l;
            Node* current2=*l;

            if(current1==tmp1){}
            else{
                while(current1->next!=tmp1)
                    current1=current1->next ;
            }

            if(current2==tmp2){}
            else{
                while(current2->next!=tmp2)
                    current2=current2->next ;
            }

          if(tmp1==*l){

          Node* tmpnext=*l;
          *l=current2->next;
          current2->next=tmpnext;

          Node* tmpnextnext=(*l)->next;
          (*l)->next=current2->next->next;
          current2->next->next=tmpnextnext;


        }else if(tmp2==*l){

          Node* tmpnext=*l;
          *l=current1->next;
          current1->next=tmpnext;

          Node* tmpnextnext=(*l)->next;
          (*l)->next=current1->next->next;
          current1->next->next=tmpnextnext;

        }

else

        {

          Node* tmpnext=current2->next;
          current2->next=current1->next;
          current1->next=tmpnext;

          Node* tmpnextnext=current2->next->next;
          current2->next->next=current1->next->next;
          current1->next->next=tmpnextnext;

            }

            Node* tmp=*first;
            *first=*second;
            *second=tmp;

        }


void displayList(list l){

    list current=l;
    printf("Printing the elements of the stack : \n");
    while(current){
        printf(" (val:%d,occ:%d) \n",current->val,current->occ);
        current=current->next;
    }
    printf("\n");

  }

void DisplayListht(listht *listp){
    list curr=listp->head;
    while(curr!=listp->tail->next) {
      printf(" %d |",curr->occ);
      curr=curr->next;
    }
    printf("\n");
  }

listht* transform(list l){

  listht* listp=malloc(sizeof(listht));
  listp->head=l;
  list current=l;
  while(current->next) current=current->next;
  listp->tail=current;

  return listp ;

}

displayNode(Node* l){

   Node* final_current=l;
   while(final_current){
   printf("| %d ",final_current->occ);
   final_current=final_current->next;
 }
 printf("\n");

}

void sort_list_by_ref(listht *l){


          Node* current=l->head;
          Node* departure=current;
          printf("now \n");
          if(!current->next){}
          else if(!current->next->next){

            if(current->occ>current->next->occ) swap_Node(&current,&current->next,&departure);
           }

          else
         {
            while(current->next){

            Node* min=current;
            Node* crawler=current->next;


            while(crawler){

                if(min->occ>crawler->occ)
                min=crawler;
                crawler=crawler->next;
            }

            swap_Node(&current,&min,&departure);

            current=current->next;

                }

            Node* tail_fix=departure;

            while(tail_fix->next) tail_fix=tail_fix->next;

            l->head=departure;
            l->tail=tail_fix;
            printf("%d\n",l->head->occ);
            printf("%d\n",l->tail->occ);

            }
        }

void suppress_Node(Node** main,Node* node){
  Node* current=*main;
  if (current==node) {

    Node* to_suppress=*main;
    *main=(*main)->next;

  }
  else{

    while(current->next!=node) current=current->next;
    current->next=current->next->next;

  }
}

Tree* find_tree(Equival* equiv, Node* node){
  Equival* current=equiv ;
  while(current->nodeattr!=node) current=current->next;

  return current->treeattr;

}

void add_node_tree(Equival** equiv, Node* node,Tree* tree){

   if(*equiv==NULL){
     Equival* current=malloc(sizeof(Equival));
     current->nodeattr=node;
     current->treeattr=tree;
     current->next=NULL;
     *equiv=current;
   }
   else{
   Equival* current=*equiv;
   while(current->next)
     current=current->next;


   current->next=malloc(sizeof(Equival));
   //current=current->next;
   current->next->nodeattr=node;
   current->next->treeattr=tree;
   current->next->next=NULL;
 }


  // return equiv;

}

void displayEquiv(Equival* equiv){
  Equival* current=equiv;
  printf("%s\n","now displaying Equival ..");
  if(current==NULL){

    printf("%s\n","no elements .. ");
  }
  else if(!current->next){
    printf("%s\n","only one element ..  ");
    printf("[Node:adress %p|Tree:adress %p]\n",current->nodeattr,current->treeattr);


  }
else
  {
      printf("%s\n","many elements .. ");
  while(current) {
     printf("[Node:adress %p|Tree:adress %p]\n",current->nodeattr,current->treeattr);
      current=current->next;

    }
   }

}


void listHuffman(listht* lis,Tree** tree){
    list current=lis->head;
    Equival *equiv={0};

    while(current->next){

        Tree* big_tree=malloc(sizeof(Tree));
        Node* root=malloc(sizeof(Node));

        if(!*tree){

          Node* first_to_add=current;
          Node* second_to_add=current->next;

          Tree* element_to_add1=malloc(sizeof(Tree));
          Tree* element_to_add2=malloc(sizeof(Tree));

          element_to_add1->root=first_to_add;
          element_to_add1->left=NULL;
          element_to_add1->right=NULL;

          element_to_add2->root=second_to_add;
          element_to_add2->left=NULL;
          element_to_add2->right=NULL;

          big_tree->left=element_to_add1;
          big_tree->right=element_to_add2;


        }else
        {
          if(current->val==0){
            if(current->next->val==0){

              big_tree->left=find_tree(equiv,current);
              big_tree->right=find_tree(equiv,current->next);

          }else
          {

            Tree* first_to_add=malloc(sizeof(Tree));

            first_to_add->root=current->next;
            first_to_add->left=NULL;
            first_to_add->right=NULL;

            big_tree->left=find_tree(equiv,current);
            printf("fuck %d\n",big_tree->left->root->occ);
            big_tree->right=first_to_add;

          }
        }else
        {
          if(current->next->val==0){

            Tree* first_to_add=malloc(sizeof(Tree));

            first_to_add->root=current;
            first_to_add->left=NULL;
            first_to_add->right=NULL;

            big_tree->left=first_to_add;
            big_tree->right=find_tree(equiv,current->next);

          }else{

            Node* first_to_add=current;
            Node* second_to_add=current->next;

            Tree* element_to_add1=malloc(sizeof(Tree));
            Tree* element_to_add2=malloc(sizeof(Tree));

            element_to_add1->root=first_to_add;
            element_to_add1->left=NULL;
            element_to_add1->right=NULL;

            element_to_add2->root=second_to_add;
            element_to_add2->left=NULL;
            element_to_add2->right=NULL;

            big_tree->left=element_to_add1;
            big_tree->right=element_to_add2;

          }
        }

        root->val=0;
        root->occ=current->occ+current->next->occ;
        root->next=NULL;

        big_tree->root=root;
        *tree=big_tree;
        add_node_tree(&equiv,root,big_tree);

        lis->tail->next=malloc(sizeof(Node));
        lis->tail->next=root;
        lis->tail=root;

        suppress_Node(&lis->head,current);
        suppress_Node(&lis->head,current->next);

        sort_list_by_ref(lis);

        current=lis->head;
      }


      }

     return *tree ;


}

void show_huffman(Tree* tree){

  if(tree){
    printf("value of node: %d\n",tree->root->occ);
    show_huffman(tree->left);
    show_huffman(tree->right);
  }
}

char* appendCharToCharArray(char* array, char a)
{
    size_t len = strlen(array);
    char* ret =malloc(sizeof(char));
    strcpy(ret, array);
    ret[len] = a;
    ret[len+1] = '\0';

    return ret;
}

// char* Huffman(Tree* tree,int el){
//   static char* result"";
//   static int el=0;
//   if(tree){
//
//     if(tree->left->root->occ==el) result=appendCharToCharArray(result,'0');
//     else
//     if(tree->right->root->occ==el) result=appendCharToCharArray(result,'1');
//
//
//   }

  return result;
  }




}




int main() {
  list *l=NULL;
  listht* lis=NULL;

  insert_element(&l,11);
  insert_element(&l,11);
  insert_element(&l,1123);
  insert_element(&l,743);
  insert_element(&l,879);
  insert_element(&l,23);
  insert_element(&l,729);
  insert_element(&l,7);
  insert_element(&l,7);
  insert_element(&l,7);
  insert_element(&l,7);
  insert_element(&l,5);
  insert_element(&l,11);
  insert_element(&l,45);
  insert_element(&l,45);
  insert_element(&l,7);
  insert_element(&l,7);
  insert_element(&l,175);
  insert_element(&l,8);
  insert_element(&l,8);
  insert_element(&l,14);
  insert_element(&l,14);
  insert_element(&l,8);
  insert_element(&l,8);
  insert_element(&l,45);
  // make a list structre with head and tail
  lis=transform(l);

  sort_list_by_ref(lis);

  //display the list of caracters + occurences
  displayList(lis->head);

  Tree* tree;
  listHuffman(lis,&tree);
  show_huffman(tree);


  return 0;
}
