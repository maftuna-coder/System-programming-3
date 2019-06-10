
/* Maftuna Sharabbaeva U1510067 (002)                                      
 This program SecondOne.c reads in an input line,then parses the input line     
 into tokens, as well as apply execvp() to run the command. */


#include  <stdio.h> //input/output functions
#include  <sys/types.h> // here include definition for pid_t which Used for process IDs and process group IDs.


/* parse function does following things:                                                  
    This function takes an input line and parse it into tokens.    
 It first replaces all white spaces with zeros until it hits a     
 non-white space character which indicates the beginning of an     
 argument.  It saves the address to argv[], and then skips all     
 non-white spaces which constitute the argument. */


void  parse(char *line, char **argv)
{

     while (*line != '\0') // if it is not the end of line
{ 

          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0'; // replace white spaces with 0 


          *argv++ = line; // save the position   

          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++; // skip the value
     }
     *argv = '\0'; // sign the end of list

}



/* execute function receives a command line argument list. First one is
 a file name followed by its values. After this, this function forks a child 
process to run the command applying system call execvp(). */
     
void  execute(char **argv)
{

     pid_t  pid;
     int    status;
     
     if ((pid = fork()) < 0) {     // fork a child procession    
          printf("Nope here is Error --> forking child procession failed\n");
          exit(1);
     }

     else if (pid == 0) //for the child procession
     {        
          if (execvp(*argv, argv) < 0) // run the command
          {     
               printf("Nope here is Error --> execution is failed\n");
               exit(0);
          }
     }
     else {
// for parent:                                    
          while (wait(&status) != pid)       //wait for finishing
               ;
                             }
}


/* The main begins  --->>> */

     
void  main(void)
{

     char  line[1024]; //the input line                 
     char  *argv[128]; // the command line argument      
     
     while (1)  // repeat till done
     {                  
          printf("Prompt ----->>>  "); //demonstrate prompt       
          gets(line); //read in command line     
          parse(line, argv); //parse line               
          if (strcmp(argv[0], "exit") == 0)  // is it "exit"?     
               exit(0);  //if it is -> exit                
          execute(argv); // otherwise, run command 

     }

}



