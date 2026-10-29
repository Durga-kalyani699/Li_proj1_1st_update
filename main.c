
#include"main.h"

int main()
{
    start:
    system("clear");

    char prompt[20];
    printf("minishell$:");

    char input[50];
    scanf("%[^\n]",input);
    if(strncmp(input,"PS1=",4)==0)
    {
        if(validate_prompt(input)==0)
        {
            printf("ERROR : Invalid prompt\n");
            sleep(1);
            goto start;
        }
        else
        {
            printf("INFO : Validation of prompt completed\n");
        }
    }
    else
    {
        char *commands[153];
        const char delim[]=" ";
        char *token = strtok(input,delim);
        int i=0;
        printf("\nThe commands in input are:\n");
        while(token != NULL && i<153)
        {
            commands[i]=token;
            printf("%s\n",commands[i]);
            token=strtok(NULL,delim);
            i++;
        }
        printf("\n");
        if(check_cmd_type(commands[0])==Builtin_cmd)
        {
            printf("INFO : It is a built in command\n");
            execute_builtin_cmd();
        }
        else if(check_cmd_type(commands[0])==External_cmd)
        {
            printf("INFO : It is a external command\n");
            int ret=fork();
            if(ret>0)
            {

            }
            if(ret==0)
            {
                execute_external_cmd(commands);
            } 
        }
        else
        {
            printf("ERROR : Invalid command\n");
        }
    }
}
int validate_prompt(char str[])
{
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
        {
            return 0;
        }
    }
    if(strlen(str)<=4)
    {
        return 0;
    }
    return 1;
}

int check_cmd_type(char* cmd)
{
    for(int i=0;builtins[i];i++)
    {
        if(strcmp(cmd,builtins[i])==0)
        {
            return Builtin_cmd;
        }
    }
    for(int i=0;externals[i] != NULL;i++)
    {
        if(strcmp(cmd,externals[i])==0)
        {
            return External_cmd;
        }
    }
    return No_cmd;
}

void execute_builtin_cmd()
{

}

void execute_external_cmd(char* commands[])
{
    for(int i=0;commands[i];i++)
    {
        if(strcmp(commands[i],"'|'")==0)
        {
            printf("INFO : Pipe present\n"); // execute n pipe
            
        }
    }

    
}

// clear the terminal (using system call impliment clear)

// extract external commands

// print prompt string (minishell$:)

// read an input string from the user

// check the input string contains "PS1="  (using strncmp)
      // if yes
        // check for spaces in string
        // YES (invalid)
           //print invalid input and start again 
        // NO
           // check for string after PS1=
              // No string  --> print error and start again
              // Yes   -->

      // if no

    // PS1 is the prompt string using this we can print the prompt repeatedly by giving PS1=promt  (no spaces)
