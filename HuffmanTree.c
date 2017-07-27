/*

Huffman coding
__@author__ = Tarek Samaali

*/

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

}Node;

typedef struct Code_Node{
  char* code;
  struct Code_Node* next;
}Code_Node ;

typedef Node* list;


typedef struct tree{

  struct Node* root ;
  struct tree* left;
  struct tree* right;

}Tree;


typedef struct list{

    list head;
    list tail;

}listht ; // list with head and tail

typedef struct equival{

  struct Node* nodeattr;
  struct Tree* treeattr;
  struct equival* next;

}Equival;



void insert_element(list** l,int el){

    if(*l==NULL){
      list current=(list)malloc(sizeof(Node));
      current->val=el ;
      current->occ=1 ;
      current->next=NULL ;
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

          current=current->next ;
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


  /*swap two nodes within a linked list using inly their references*/
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

/*Transform a list to head-and-tail-based list */
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

/*Sorting a linked list using only the references of the elements (only pointers) */
void sort_list_by_ref(listht *l){


          Node* current=l->head;
          Node* departure=current;
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
            //printf("%d\n",l->head->occ);
            //printf("%d\n",l->tail->occ);

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


/* build the huffman tree*/
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

/*display the elements of Huffman Tree in order */
void show_huffman(Tree* tree){

  if(tree){
    printf("value of node: %d\n",tree->root->occ);
    show_huffman(tree->left);
    show_huffman(tree->right);
  }
}


/*find the parent of a node within the Huffman tree*/
Tree* look_for_parent(Tree *p,Tree* orphan){
  static Tree* output={0};

  if(p!=orphan)
  {
    if (!p)
      {
        return;
    }

  if(p->left==orphan) output=p;
    else
  if(p->right==orphan) output=p;

  look_for_parent(p->left,orphan);
  look_for_parent(p->right,orphan);

  return output;

    }else{
  return p ;
}


}

/*search for a particular element in the tree */
Tree* in_order_search(Tree *p, int val)
{
    static Tree* output;
    if (!p)
    {
        return;
    }
    in_order_search(p->left, val);
    if(p->root->val == val)
    {

        output=p;

    }
    in_order_search(p->right, val);

    return output;
}

char* build_caracter_huffman(Tree* root,Tree* start){
  if(look_for_parent(root,start)->right==start)
    return "1";
  else if (look_for_parent(root,start)->left==start)
    return "0";

}

/*append a char array to another*/
char* apprend(char *a,char *b)
{
  char *out;
  if((out = (char *)malloc(strlen(a) + strlen(b) + 1)) != NULL)
  {
   strcpy(out, a);
   strcat(out, b);
 }
 else{};
  return out;
}

/* Applying the huffman coding procedure to code the integer values */
char* codehuffman(Tree* tree,int val)
{
  char* output="";
  Tree* start=in_order_search(tree,val);
  while (start!=look_for_parent(tree,start)) {
    output=apprend(build_caracter_huffman(tree,start),output);
    start=look_for_parent(tree,start);
  }

  return output;
}

/*We build a list of coded elements at this stage*/
void add_code(Code_Node **code_list, char* el){

   Code_Node* current=*code_list;
   if(current==NULL){
     current=malloc(sizeof(Code_Node));
     current->code=el;
     current->next=NULL;
     *code_list=current;
   }
   else{
     while(current->next) current=current->next;
     current->next=malloc(sizeof(Code_Node));
     current=current->next;
     current->code=el;
     current->next=NULL;
   }
}

/*code all the tree elements */
Code_Node* build_all_huffman(Tree* tree,Tree* root){

  static Code_Node* code_list;

  if(!tree){}
  else{

  if(tree->root->val)
      {
      int val =tree->root->val;
      char* code=codehuffman(root,val);
      add_code(&code_list,code);
      printf("Value: %6d |   Huffman code: %s \n",val,code);
    }
  build_all_huffman(tree->left,root);
  build_all_huffman(tree->right,root);

  }
  return code_list;
}

/*decode an element*/
Tree* decodehuffman(char* code,Tree* root){
   Tree* start=root;
   int counter=0;

   while(*(code+counter)){
     if (*(code+counter)=='1') start=start->right;
     if (*(code+counter)=='0') start=start->left;
     counter++;
   }
   return start ;
}

void decode_all_huffman(Code_Node* listcode, Tree* root){
    //Code_Node* current=listcode;
    if(listcode){
      printf("Huffman code: %8s | Value: %6d \n",listcode->code,decodehuffman(listcode->code,root)->root->val);
      decode_all_huffman(listcode->next,root);
    }

}

int main(int argc, char** argv) {
  list *l=NULL;
  listht* lis=NULL;
  Tree* tree;
  Code_Node* list_code;

  int i;
    
  /* add elements using command line arguments */
  for(i = 1; i < argc; i++)
    insert_element(&l,atoi(*(argv+i)));
  printf("\n\n");

 /*uncomment to add elements manually*/

  // insert_element(&l,11);
  // insert_element(&l,11);
  // insert_element(&l,1123);
  // insert_element(&l,743);
  // insert_element(&l,879);
  // insert_element(&l,23);
  // insert_element(&l,729);
  // insert_element(&l,7);
  // insert_element(&l,7);
  // insert_element(&l,7);
  // insert_element(&l,7);
  // insert_element(&l,5);
  // insert_element(&l,11);
  // insert_element(&l,45);
  // insert_element(&l,45);
  // insert_element(&l,7);
  // insert_element(&l,7);
  // insert_element(&l,8);
  // insert_element(&l,8);
  // insert_element(&l,14);
  // insert_element(&l,14);
  // insert_element(&l,8);
  // insert_element(&l,8);
  // insert_element(&l,45);
  // insert_element(&l,45);

  // make a list structure with head and tail
   lis=transform(l);
   sort_list_by_ref(lis);
  
  // //display the list of caracters + occurences
  listHuffman(lis,&tree);
  //
    
  /*main part */
  /* Coding */
  printf("%s\n\n","Coding : ");
  list_code=build_all_huffman(tree,tree);
  printf("\n\n");
    
  /*Decoding*/
  printf("%s\n\n","Decoding : ");
  decode_all_huffman(list_code,tree);
  printf("\n");

return 0;
}
