#pragma once

#ifdef __cplusplus
  extern "C"{
#endif

  typedef void* LinkList;
  typedef void(*Callback)(void *);



  int init_LinkList(LinkList * linklist);
  unsigned int getSize_LinkList(LinkList linklist);
  int insert_LinkList(void* data,unsigned int pos, LinkList linklist);
  void foreach_LinkList(LinkList linklist, Callback callback);
  int delete_LinkList(LinkList linklist,unsigned int pos);
  void destroy_LinkList(LinkList linklist);


#ifdef __cplusplus
  }
#endif
