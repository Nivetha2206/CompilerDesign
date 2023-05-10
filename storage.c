#include <stdio.h>
#include <malloc.h>

int top;
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int main(){
    int choice,choice2, n;
    printf("Enter value: ");
    scanf("%d",&n);

    struct node *curr;
    struct node *curr2;
    struct node new;
    struct node top;

    new=(struct node*)malloc(sizeof(struct node));
    
    curr=new;
    curr->data=n;
    top=curr;
    curr->prev=NULL;

    do{
        print("Push or pop? 1/2");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter value: ");
            scanf("%d",&n);

            new = (struct node*)malloc(sizeof(struct node));
            new->data = n;
            new->prev=curr;
            curr=new;
            top=curr;
            //printf
            break;

            case 2:
            printf("Enter value: ");
            scanf("%d",&n);
            top=top->prev;
            free(curr);
            curr = top;
            break;

        }

        curr2=top;
        while(curr2!=NULL){
            printf("%d",curr2->data);
            if (curr2->prev!=NULL){
                printf("->");
            }
            curr2=curr2->prev;
        }
        printf("Continue? y/n");
        scanf("%d",&choice2)

    }while (choice2=='y';
    return 0;)


}