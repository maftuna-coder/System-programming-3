
/* Maftuna Sharabbaeva U1510067 (002)
Part1 */


#include <stdio.h> //input/output functions

#include <signal.h> /*defines several macros to handle different signals reported during a program's execution
such as SIGINT which corresponds to event of interrupting from keyboard and 
for example it is used such as if you type a ctrl-c whiche a process is running in the foreground, then the kernel sends a SIGINT to the foreground process */


static int MAXIMALLIMIT;

void SIGINTHandler(int sig_num) //SIGINT handler
{
    static int counter = 0;
    counter++;

       if (counter==MAXIMALLIMIT)//if it is at user inputted limit then exit
       {
           printf("\n You pressed Ctrl-C  --->>> %d times :P \n it is max limit ->%d Hey hey Hey finished Goooood Byeee :))) \n",
  counter, MAXIMALLIMIT);
           exit(0);
       }

    signal(SIGINT, SIGINTHandler);// otherwise, install the SIGINT handler

/*showing message about how many Ctrl-C were inputted -> */
    printf("\n You pressed Ctrl-C  --->>> %d times :P  \n", counter); 
    fflush(stdout); /*this function is to ensure that whatever I wrote in console is indeed written out on the console.
    I need it because I am showing prompt without a newline, and I am willing to make sure the user can see it */
    
}


//hhere main begins ->>>
int main ()
{
    printf("\n How many time you are willing to press Ctrl-C ?? Enter->  \n");//showing message to get limit number
    scanf("%d",&MAXIMALLIMIT); //getting input
    signal(SIGINT, SIGINTHandler); //install the SIGINT handler

    while(1)
    {
//long wait, this is why -->>> we can easily say a signal to this procession
    }

    return 0;
}
