#include <stdio.h>
#include "LinkList.h"

struct Person{
    char name[20];
    int age;
};
void dayin (void * data){

    struct Person  p = *((struct Person *)data);
    printf("%s--%d\n",p.name,p.age);
}
int main()
{

    LinkList linklist = NULL;
     init_LinkList(&linklist);
    struct Person p1 = {"111",11};
    struct Person p2 = {"333",12};
    struct Person p3 = {"444",13};

    insert_LinkList(&p1,3,linklist);
    insert_LinkList(&p2,3,linklist);
    insert_LinkList(&p3,3,linklist);
    foreach_LinkList(linklist,dayin);

    printf("-------------\n");
    delete_LinkList(linklist,2);
    foreach_LinkList(linklist,dayin);

    return 0;
}
