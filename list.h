#ifndef LIST_H
#define LIST_H

/* List (Queue) Architecture */
typedef struct Node Node;
typedef struct List List;

struct Node {
	Node*	next;
	void*	dat;
};

struct List {
	Node*	root;
	int		size;
};

// Create a new list
List mklist(void);

// Append to a list
void ladd(List*, void*);

// Search → delete from a list
void* ldel(List*, void*, int(*comp)(void *, void *));

// Access elements of a list by 'index'
void* lget(List*, int);

#endif
