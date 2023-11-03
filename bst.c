#include <stdio.h>
#include <stdlib.h>

// this shows the structure of a node
struct TreeNode {
    int dataPoint;
    struct TreeNode* left;
    struct TreeNode* right;
};

// this will create a new node
struct TreeNode* createNode(int dataPoint) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if ( newNode == NULL ) {
        printf( "Memory allocation = failed" );
        exit( 1 );
    }
    newNode -> dataPoint = dataPoint;
    newNode -> right = NULL;
    newNode -> left = NULL;
    
    return newNode;
}

// this will insert a value into the bst
int insert( struct TreeNode** rootNode , int NodeValue ) {

    if ( *rootNode == NULL ) {

        *rootNode = createNode( NodeValue );
        return 1; // Inserted

    } else if ( NodeValue > ( *rootNode ) -> dataPoint ) {

        return insert( &( *rootNode ) -> right , NodeValue );

    } else if ( NodeValue < ( *rootNode ) -> dataPoint ) {

        return insert( &( *rootNode ) -> left , NodeValue );

    } else {
        
        return 0; // this means value exists already
    }
}

// Function to search for a value in the binary search tree
int search( struct TreeNode* rootNode , int NodeValue ) {
    if ( rootNode == NULL ) {

        return 0; // it is not there

    } else if ( NodeValue > rootNode -> dataPoint ) {

        return search( rootNode -> right , NodeValue );

    } else if ( NodeValue < rootNode -> dataPoint ) {

        return search( rootNode -> left , NodeValue );

    } else {

        return 1; // it is there
    }
}

// will print binary search tree
void print( struct TreeNode* rootNode ) {
    if ( rootNode != NULL ) {

        print( rootNode -> left );
        printf( "%d " , rootNode -> dataPoint );
        print( rootNode -> right) ;
    }
}

// this will help find the minimum value in bst
struct TreeNode* findMin( struct TreeNode* rootNode ) {
    for ( ; rootNode -> left != NULL; rootNode = rootNode -> left ) {
    }
    return rootNode;
}

// this will delete value from bst
int delete( struct TreeNode** rootNode , int NodeValue ) {
    if ( *rootNode == NULL ) {

        return 0; // Absent

    } else if ( NodeValue < ( *rootNode ) -> dataPoint ) {

        return delete( &( *rootNode ) -> left , NodeValue );

    } else if ( NodeValue > ( *rootNode ) -> dataPoint ) {

        return delete( &( *rootNode ) -> right , NodeValue );

    } else if ( ( *rootNode ) -> left == NULL) { // the value is found

            struct TreeNode* temp = *rootNode;
            *rootNode = ( *rootNode ) -> right;
            free( temp );

        } else if ( ( *rootNode ) -> right == NULL ) {

            struct TreeNode* temp = *rootNode;
            *rootNode = ( *rootNode ) -> left;
            free( temp );

        } else {
            // this will take the node with 2 children and put the min value in the right subtree

            struct TreeNode* temp = findMin( ( *rootNode ) -> right );
            ( *rootNode ) -> dataPoint = temp -> dataPoint;

            return delete( &( *rootNode ) -> right , temp -> dataPoint );
        }
        return 1; // it is deleted
    
}

int main() {
    struct TreeNode* rootNode = NULL;
    int NodeValue;
    char task;

// this just follows the rules of what needs to happen for each command
    for ( ; scanf( " %c%d" , &task, &NodeValue ) == 2; ) {
    if ( task == 's' ) {
        if ( search(rootNode , NodeValue ) ) {
            printf( "present\n" );
        } else {
            printf( "absent\n" );
        }
    } else if ( task == 'i' ) {
        if ( insert( &rootNode , NodeValue ) ) {
            printf( "inserted\n" );
        } else {
            printf( "not inserted\n" );
        }
    } else if ( task == 'd' ) {
        if ( delete( &rootNode , NodeValue ) ) {
            printf( "deleted\n" ) ;
        } else {
            printf( "absent\n" );
        }
    } else if ( task == 'p' ) {
        print( rootNode );
        printf( "\n" );
    } else {
        printf( "Did not work" );
    }
}
    // this will release the memory that the bst used
   do {
        delete(&rootNode, rootNode->dataPoint);
    } while (rootNode != NULL);

    return 0;
}