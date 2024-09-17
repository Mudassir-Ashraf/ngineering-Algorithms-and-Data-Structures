#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern char *  pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int ch, var, poppedch;
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    else if(ch=='<')
    {
        ch = getchar(); //Read another stdin
        if(isalpha(ch)){
                var = getchar();
                if((var =='>')&& (var !=EOF)){//another else if check if there is / then its a stand alone(clsing and opening
                          push(ch); //Only push ch onto the stack when you have a complete tag
                }
                else{
                printf("Incomplete tag. Try running again!");
                exit(1);
                }
        }
       else if(ch =='/'){
            ch = getchar();
            if(isalpha(ch))//if ch is an alphabet
            {
                     var = getchar();
                      if((var =='>')&& (var !=EOF))
                      {
                           if((isEmpty()) == 1){ //if the stack is empty then you can't pop
                              fprintf(stderr,"The stack can't be popped because it's empty\n");
                              exit(0);
                           }

                           else if((poppedch = pop())== ch ) //if the stack isn't empty then you can pop and check poppedch against ch
                           {
                                  continue;
                           }
                           else //if the stack isn't empty then you can pop
                                 fprintf(stderr,"Invalid! The top of the stack doesn't match the popped character.\n");
                                 exit(1);
                           {

                           }
                      }
                      else{ //else for the closing '>' if
                         fprintf(stderr, "The closing identifier was not detected." );
                         exit(1);
                      }
            }
      }
  } //closing for if of '<'
  else{
      exit(0);
  }
} //Closing of while loop
  if((isEmpty())== 1){
    printf("Valid!\n");
    exit(0);}
  else{
    printf("Invalid!\n");
    exit(1);}
}



 
