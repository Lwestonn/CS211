#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Struct to hold the open and close braces and the pointer to the next element.
struct element {
    // char open; // not needed
    char close;
    struct element* next;
};

// Append the new element to the start of the stack
// This is one potential way to write this function signature
struct element* push (
    struct element* stack,
    // char open, // not needed
    char close
) {
    /* ... */
	//check
	struct element* newElm = (struct element*) malloc(sizeof(struct element));
	if(!newElm){
		perror("malloc failed");
		//return close;
		return stack;
	}
	newElm->close=close;

	newElm->next=stack;

		return newElm;
}

// Remove element from the top of the stack
char pop ( struct element** stack ) {

    if (*stack != NULL) {
        /* ... */
	    struct element* old_head=*stack;



//if(*stack!=1)
	    char close = old_head->close;
	//head of stack
	    *stack = old_head->next;

	    free(old_head);
	    //return close
	    return close;
    } else {

        return '\0';
    }
}

int main(int argc, char* argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    struct element* root = NULL;
    bool balanced = true;

    char buff;
    while ( fscanf(fp, "%c", &buff)==1 ) {

        switch(buff) {

            case '<' :
	     //push for non left sided	    
		    root = push(root,'>');
		    break;

            case '(' :

                root = push(root,')');
		break;

            case '[' :

                root = push(root, ']');
		break;

            case '{' :

                root = push(root, '}');
		break;

            case '>' :
		//pop off of stack and change balanced boolean for return statement
                if(pop(&root) != '>'){
		balanced = false;
		break;		
		}
		break;

            case ')' :
		//check all
                if(pop(&root) != ')'){
		balanced = false;
		break;
		}
		break;

            case ']' :

               	if(pop(&root) != ']'){
		balanced = false;
		break;
		}
		break;

            case '}' :

                if(pop(&root)!='}'){
		balanced = false;
		break;
		}
		break;

            default :

                printf("Invalid character\n" );
		break;

        }
    }
//checker
//check for null
   if(root!=NULL){
	//balanced boolean based on pop from stack
	   balanced = false;

   }

    printf ( balanced ? "yes" : "no" );
    fclose(fp);
    return 0;
}
