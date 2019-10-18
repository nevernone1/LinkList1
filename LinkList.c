#include "LinkList.h"
#include <stdlib.h>

struct LinkNode{
  void * data;
  struct LinkNode * next;
};

struct LList{
  struct LinkNode* header;
  unsigned int size;

};

int init_LinkList(LinkList * linklist){
    struct LList * llist = (struct LList *)malloc(sizeof (struct LList));
    if(llist == NULL){
        return 0;
    }
    struct LinkNode * headNode= (struct LinkNode *) malloc(sizeof (struct LinkNode));
    if(headNode == NULL){
        return 0;
    }
    headNode->data = NULL;
    headNode->next = NULL;

    llist->header = headNode;
    llist->size = 0;

    *linklist = (LinkList)llist;
    return 0;
}

unsigned int getSize_LinkList(LinkList linklist){
    if(linklist == NULL){
        return 0;
    }
    return ((struct LList *)linklist)->size;
}


int insert_LinkList(void* data,unsigned int pos, LinkList linklist){
    if(linklist == NULL){
        return 0;
    }
    struct LinkNode * newNode = (struct LinkNode*)malloc(sizeof (struct LinkNode));
    if(newNode == NULL){
        return 0;
    }
    newNode->data = data;
    newNode->next = NULL;

    struct LList * list = (struct LList *)linklist;
    struct LinkNode * node = list->header;
    if(node == NULL){
        struct LinkNode * headNode= (struct LinkNode *) malloc(sizeof (struct LinkNode));
        if(headNode == NULL){
            return 0;
        }
        headNode->data = NULL;
        headNode->next = NULL;
        node = headNode;
    }
    if(pos >= list->size){

        for(unsigned int i = 0; i < list->size; i ++){
            node = node->next;
        }
        node->next = newNode;

    }else {

        for(unsigned int i = 0; i < list->size; i ++){
            node = node->next;
        }
        struct LinkNode * nextnode = node->next;
        node->next = newNode;
        newNode->next = nextnode;

    }
    list->size = list->size + 1;
    return 1;
}

void foreach_LinkList(LinkList linklist, Callback callback){
    if(linklist == NULL){
        return;
    }
    if(callback == NULL){
        return;
    }
    struct LList * list = (struct LList *)linklist;
    if(list->size == 0){
        return;
    }
    struct LinkNode * node = list->header;
    for(unsigned int i = 0; i < list->size; i++){
        node = node->next;
       callback(node->data);
    }
}

int delete_LinkList(LinkList linklist,unsigned int pos){
    if(linklist == NULL){
        return 0;
    }
    struct LList * list = (struct LList *)linklist;
    if (pos > list->size - 1){
        return 0;
    }
    struct LinkNode * node = list->header;
    for(unsigned int i = 0; i < pos; i ++){
        node = node->next;
    }
    struct LinkNode * deletenode = node->next;
    node->next = deletenode->next;
    list->size --;
    free(deletenode);
    return 1;
}

void destroy_LinkList(LinkList linklist){
    if(linklist == NULL){
        return;
    }
    struct LList * list = (struct LList *)linklist;

    if(list->size == 0){
       free(list->header);
       list->header = NULL;
       free(linklist);
       linklist = NULL;
        return;
    }else {

        struct LinkNode * node = list->header;
        free(list);
        list = NULL;
        while (node != NULL) {
            struct LinkNode * nextnode = node->next;
            free(node);
            node = nextnode;
        }
    }

}
